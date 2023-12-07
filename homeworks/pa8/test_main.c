#include <stdio.h>
#include <stdlib.h>
#include "matrix_mult.h"

void print_matrix(double *matrix, int dim);

int main() {
    int dim = DIM;
    int num_workers = NUM_WORKERS;

    // Allocate memory for matrices
    double *matrix_a = calloc(dim * dim, sizeof(double));
    double *matrix_b = calloc(dim * dim, sizeof(double));
    double *matrix_c_serial = calloc(dim * dim, sizeof(double));
    double *matrix_c_parallel = calloc(dim * dim, sizeof(double));

    if (!matrix_a || !matrix_b || !matrix_c_serial || !matrix_c_parallel) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Return with error code
    }

    // Initialize matrices A and B
    init_matrix(matrix_a, dim);
    init_matrix(matrix_b, dim);

    // Print SERIAL INPUT
    //printf("SERIAL INPUT:\n");
    //print_matrix(matrix_a, dim);
    //print_matrix(matrix_b, dim);

    // Perform serial matrix multiplication
    multiply_serial(matrix_a, matrix_b, matrix_c_serial, dim);

    // Print SERIAL OUTPUT
    //printf("SERIAL OUTPUT:\n");
    //print_matrix(matrix_c_serial, dim);

    // Print PARALLEL INPUT
    //printf("PARALLEL INPUT:\n");
    //print_matrix(matrix_a, dim);
    //print_matrix(matrix_b, dim);

    // Perform parallel matrix multiplication
    multiply_parallel_processes(matrix_a, matrix_b, matrix_c_parallel, dim, num_workers);

    // Print PARALLEL OUTPUT
    //printf("PARALLEL OUTPUT:\n");
    //print_matrix(matrix_c_parallel, dim);

    // Compare the results
    for (int i = 0; i < dim * dim; i++) {
        if (matrix_c_serial[i] != matrix_c_parallel[i]) {
            printf("Mismatch found at index %d\n", i);
            return 1;  // Return with error code indicating mismatch
        }
    }

    printf("Success: Serial and Parallel results match.\n");


    struct timeval start, end;

    // Perform and time serial matrix multiplication
    gettimeofday(&start, NULL);
    multiply_serial(matrix_a, matrix_b, matrix_c_serial, dim);
    gettimeofday(&end, NULL);
    print_elapsed_time(&start, &end, "Serial");

    // Perform and time parallel matrix multiplication
    gettimeofday(&start, NULL);
    multiply_parallel_processes(matrix_a, matrix_b, matrix_c_parallel, dim, num_workers);
    gettimeofday(&end, NULL);
    print_elapsed_time(&start, &end, "Parallel");
    // Free allocated memory
    free(matrix_a);
    free(matrix_b);
    free(matrix_c_serial);
    free(matrix_c_parallel);

    return 0;
}

