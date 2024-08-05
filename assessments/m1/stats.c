/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Implementation file for data analysis functions
 *
 * This file contains functions to analyze an array of unsigned char data items
 * and report analytics on the maximum, minimum, mean, and median of the data set.
 * Additionally, it includes functions to sort the data set and print the results.
 *
 * @author Yaroslav Kishchuk
 * @date 2024-07-22
 */

#include <stdio.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {
    unsigned char test[SIZE] = { 34, 201, 190, 154, 8, 194, 2, 6,
                                 114, 88, 45, 76, 123, 87, 25, 23,
                                 200, 122, 150, 90, 92, 87, 177, 244,
                                 201, 6, 12, 60, 8, 2, 5, 67,
                                 7, 87, 250, 230, 99, 3, 100, 90 };

    unsigned char minimum, maximum, mean, median;

    minimum = find_minimum(test, SIZE);
    maximum = find_maximum(test, SIZE);
    mean = find_mean(test, SIZE);
    median = find_median(test, SIZE);
    
    sort_array(test, SIZE);
    
    print_statistics(minimum, maximum, mean, median);
    print_array(test, SIZE);
}

void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median) {
    printf("Statistics:\n");
    printf("Minimum: %u\n", minimum);
    printf("Maximum: %u\n", maximum);
    printf("Mean: %u\n", mean);
    printf("Median: %u\n", median);
}

void print_array(unsigned char *array, unsigned int length) {
    printf("Array: ");
    for (unsigned int i = 0; i < length; i++) {
        printf("%u ", array[i]);
    }
    printf("\n");
}

unsigned char find_median(unsigned char *array, unsigned int length) {
    sort_array(array, length);
    if (length % 2 == 0) {
        return (array[length/2 - 1] + array[length/2]) / 2;
    } else {
        return array[length/2];
    }
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
    unsigned char max = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
    unsigned char min = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void sort_array(unsigned char *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                unsigned char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
