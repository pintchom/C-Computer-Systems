#ifndef MATRIX_MULT_H
#define MATRIX_MULT_H

#include <stdbool.h>
#include <sys/time.h>

#define DIM 1024
#define NUM_WORKERS 4
#define SUCCESS 0
#define FAILURE -1

typedef void (* multiply_function)(const double * const a, const double * const b, double * const c, const int dim, const int num_workers);

typedef struct {
    const double *a;
    const double *b;
    double *c;
    int dim;
    int row_start;
    int chunk_size;
} Args;

void init_matrix(double * matrix, int dim);
void multiply_serial(const double * const a, const double * const b, double * const c, const int dim, const int num_workers);
void multiply_parallel_processes(const double * const a, const double * const b, double * const c, const int dim, const int num_workers);
void multiply_parallel_threads(const double * const a, const double * const b, double * const c, const int dim, const int num_workers);
void print_matrix(double * matrix, int dim);
int verify(const double * m1, const double * m2, int dim);
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
        );
struct timeval time_diff(const struct timeval * start, const struct timeval * end);

#endif
