#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLES 10000
#define RUNS 50000
#define BINS 64
#define HISTOGRAM_SPAN 0.05
#define SCALE 32

double get_mean_of_uniform_random_samples() {
    double sum = 0.0;
    for (int i = 0; i < SAMPLES; i++) {
        double random_value = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
        sum += random_value;
    }
    return sum / SAMPLES;
}

double populate_values_and_get_mean(double *values) {
    double sum_of_means = 0.0;
    for (int i = 0; i < RUNS; i++) {
        values[i] = get_mean_of_uniform_random_samples();
        sum_of_means += values[i];
    }
    return sum_of_means / RUNS;
}

double get_mean_squared_error(double *values, double overall_mean) {
    double sum_of_squared_errors = 0.0;
    for (int i = 0; i < RUNS; i++) {
        double error = values[i] - overall_mean;
        sum_of_squared_errors += error * error;
    }
    return sum_of_squared_errors / RUNS;
}

void create_histogram(double *values, int *counts) {
    double bin_size = HISTOGRAM_SPAN / BINS;
    for (int i = 0; i < RUNS; i++) {
        int bin_index = (int)((values[i] + HISTOGRAM_SPAN / 2.0) / bin_size);
        if (bin_index >= 0 && bin_index < BINS) {
            counts[bin_index]++;
        }
    }
}

void print_histogram(int *counts) {
    double bin_size = HISTOGRAM_SPAN / BINS;
    double bin_start, bin_mid;
    for (int i = 0; i < BINS; i++) {
        bin_start = -(HISTOGRAM_SPAN/2) + i * bin_size;
        bin_mid = bin_start + bin_size / 2;
        printf("%.4f: ", bin_mid);
        for (int j = 0; j < counts[i] / SCALE; j++) {
            printf("X");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    double *values = (double *) malloc(RUNS * sizeof(double));
    int *counts = (int *) calloc(BINS, sizeof(int));

    if (!counts) {
        printf("Memory allocation for counts failed!\n");
        free(values);
        return 1;
    }

    double overall_mean = populate_values_and_get_mean(values);
    double mean_squared_error = get_mean_squared_error(values, overall_mean);
    create_histogram(values, counts);
    print_histogram(counts);

    printf("Sample Mean: %f\t", overall_mean);
    printf("Sample Variance: %f\n", mean_squared_error);

    free(values);
    free(counts);
    return 0;
}

