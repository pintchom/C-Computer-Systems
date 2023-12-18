#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>
#include "matrix_mult.h"

void init_matrix(double * matrix, int dim) {
    double k = 1.0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            matrix[i * dim + j] = k++;
        }
    }
}

void multiply_serial(const double * const a, const double * const b, double * const c, const int dim, const int num_workers) {
    (void)num_workers;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            c[i * dim + j] = 0.0;
            for (int k = 0; k < dim; k++) {
                c[i * dim + j] += a[i * dim + k] * b[k * dim + j];
            }
        }
    }
}

void * mmap_checked(size_t size) {
    void * ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void munmap_checked(void * ptr, size_t size) {
    if (munmap(ptr, size) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }
}

pid_t fork_checked() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return pid;
}

void multiply_chunk(const double * a, const double * b, double * c, int dim, int row_start, int chunk_size) {
    for (int i = row_start; i < row_start + chunk_size; i++) {
        for (int j = 0; j < dim; j++) {
            c[i * dim + j] = 0;
            for (int k = 0; k < dim; k++) {
                c[i * dim + j] += a[i * dim + k] * b[k * dim + j];
            }
        }
    }
}

void multiply_parallel_processes(const double * const a, const double * const b, double * const c, const int dim, const int num_workers) {
    int chunk_size = dim / num_workers;
    double *shared_c = mmap_checked(dim * dim * sizeof(double));

    for (int i = 0; i < num_workers - 1; i++) {
        int row_start = i * chunk_size;
        if (fork_checked() == 0) {
            multiply_chunk(a, b, shared_c, dim, row_start, chunk_size);
            exit(0);
        }
    }
    multiply_chunk(a, b, shared_c, dim, (num_workers - 1) * chunk_size, chunk_size);

    while (wait(NULL) > 0);
    for (int i = 0; i < dim * dim; i++) {
        c[i] = shared_c[i];
    }
    munmap_checked(shared_c, dim * dim * sizeof(double));
}

struct timeval time_diff(const struct timeval * start, const struct timeval * end) {
    struct timeval diff;
    diff.tv_sec = end->tv_sec - start->tv_sec;
    diff.tv_usec = end->tv_usec - start->tv_usec;

    if (diff.tv_usec < 0) {
        diff.tv_sec--;
        diff.tv_usec += 1000000;
    }
    return diff;
}

void print_elapsed_time(const struct timeval * start, const struct timeval * end, const char *const name, int num_workers) {
    struct timeval diff = time_diff(start, end);
    const char * worker_plural = (num_workers == 1) ? "worker" : "workers";
    printf("Algorithm: %s with %d %s.\n", name, num_workers, worker_plural);
    printf("Time elapsed for %s: %ld seconds and %ld microseconds\n", name, (long)diff.tv_sec, (long)diff.tv_usec);
}

int verify(const double * m1, const double * m2, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (m1[i * dim + j] != m2[i * dim + j]) {
                return FAILURE;
            }
        }
    }
    return SUCCESS;
}

void print_verification(const double * m1, const double * m2, int dim, const char * const name) {
    if (verify(m1, m2, dim) == SUCCESS) {
        printf("Verification for %s: success.\n", name);
    } else {
        printf("Verification for %s: failure.\n", name);
    }
}

void * task(void * arg) {
    Args * args = (Args *)arg;
    multiply_chunk(args->a, args->b, args->c, args->dim, args->row_start, args->chunk_size);
    return NULL;
}

void multiply_parallel_threads(const double * const a, const double * const b, double * const c, const int dim, const int num_workers) {
    int num_threads = num_workers - 1;
    pthread_t threads[num_threads];
    Args arg_set[num_workers];
    int chunk_size = dim / num_workers;
    int row_start = 0;

    for (int i = 0; i < num_workers; ++i) {
        arg_set[i].a = a;
        arg_set[i].b = b;
        arg_set[i].c = c;
        arg_set[i].dim = dim;
        arg_set[i].row_start = row_start;
        arg_set[i].chunk_size = (i == num_workers - 1) ? dim - row_start : chunk_size;
        row_start += chunk_size;
    }
    for (int id = 0; id < num_threads; ++id) {
        pthread_create(&threads[id], NULL, task, (void *)&arg_set[id]);
    }
    task((void *)&arg_set[num_workers - 1]);
    for (int id = 0; id < num_threads; ++id) {
        pthread_join(threads[id], NULL);
    }
}


void run_and_time(
        multiply_function multiply_matrices,
        const double * const a,
        const double * const b,
        double * const c,
        const double * const gold,
        const int dim,
        const char * const name,
        const int num_workers,
        const bool verify
        ) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    multiply_matrices(a, b, c, dim, num_workers);
    gettimeofday(&end, NULL);
    print_elapsed_time(&start, &end, name, num_workers);
    if (verify) {
        print_verification(c, gold, dim, name);
    }
}
