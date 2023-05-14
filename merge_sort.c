#include <string.h>
#include "merge_sort.h"

#define DOUBLE_LEN 17
#define BUFFER 100

void merge(double *array, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int *leftArray = (int *) malloc(n1 * sizeof(int));
    int *rightArray = (int *) malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    free(leftArray);
    free(rightArray);
}

void mergeSort(double *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int getLen(FILE *filePtr) {
    char string[BUFFER];
    int count = 0;
    while (fscanf(filePtr, "%s", string) == true) {
        if (strlen(string) > DOUBLE_LEN) {
            printf("Error while parsing text file: \"%s\" is too large to convert to double!", string);
            exit(EXIT_FAILURE);
        }
        count++;
    }
    rewind(filePtr);
    return count;
}

double *parse(FILE *filePtr, int len) {
    char string[BUFFER];
    double *array;
    array = (double *) malloc(len * sizeof(double));
    char *endPtr;
    int i = 0;
    while (fscanf(filePtr, "%s", string) == true) {
        double num = strtof(string, &endPtr);
        if (*endPtr != '\0') {
            printf("Error while parsing text file: can't convert \"%s\" to double!\n", string);
            exit(EXIT_FAILURE);
        }
        array[i] = num;
        i++;
    }
    return array;
}

void writeToFile(double *array, int len, FILE *outputFilePtr) {
    for (int i = 0; i < len; i++) {
        fprintf(outputFilePtr, "%F\n", array[i]);
    }
}
