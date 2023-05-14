#ifndef FLITA_MERGE_SORT_MERGE_SORT_H
#define FLITA_MERGE_SORT_MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DOUBLE_LEN 17
#define BUFFER 100

void merge(double *array, int left, int middle, int right);

void mergeSort(double *array, int left, int right);

int getLen(FILE *filePtr);

double *parse(FILE *filePtr, int len);

void writeToFile(double *array, int len, FILE *outputFilePtr);

#endif
