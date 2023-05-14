#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"

#define BILLION 1000000000.0

int main() {
    for (int i = 0; i < 9; i++) {
        char inputFilePath[100];
        char outputFilePath[100];
        sprintf(inputFilePath, "../test_data/numbers%d.txt", i);
        sprintf(outputFilePath, "../sorted_arrays/numbers%d.txt", i);
        FILE *inputFilePtr;
        FILE *outputFilePtr;
        inputFilePtr = fopen(inputFilePath, "r");
        if (inputFilePtr == NULL) {
            puts("Error opening file");
            exit(EXIT_FAILURE);
        }
        int len = getLen(inputFilePtr);
        double *array = parse(inputFilePtr, len);
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);
        mergeSort(array, 0, len - 1);
        clock_gettime(CLOCK_REALTIME, &end);
        fclose(inputFilePtr);
        double timeSpent = (double) (end.tv_sec - start.tv_sec) +
                                 (end.tv_nsec - start.tv_nsec) / BILLION;
        outputFilePtr = fopen(outputFilePath, "w");
        writeToFile(array, len, outputFilePtr);
        free(array);
        FILE *statisticsFilePtr;
        statisticsFilePtr = fopen("../statistics.txt", "a");
        fprintf(statisticsFilePtr, "%d:%f\n", len, timeSpent);
        fclose(statisticsFilePtr);
    }
    return EXIT_SUCCESS;
}
