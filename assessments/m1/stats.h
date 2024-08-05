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
 * @file stats.h 
 * @brief Header file for data analysis functions
 *
 * This file contains the declarations for functions to analyze an array of 
 * unsigned char data items and report analytics on the maximum, minimum, 
 * mean, and median of the data set. Additionally, it includes function 
 * declarations to sort the data set and print the results.
 * 
 * @author Yaroslav Kishchuk
 * @date 2024-07-22
 */

#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function prints the minimum, maximum, mean, and median of the given data set.
 *
 * @param minimum Minimum value in the data set
 * @param maximum Maximum value in the data set
 * @param mean Mean value of the data set
 * @param median Median value of the data set
 */
void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median);

/**
 * @brief Prints the array to the screen
 *
 * Given an array of data and a length, this function prints the array to the screen.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median value of the data set
 *
 * Given an array of data and a length, this function returns the median value.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 * @return Median value of the data set
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean value of the data set
 *
 * Given an array of data and a length, this function returns the mean value.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 * @return Mean value of the data set
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum value of the data set
 *
 * Given an array of data and a length, this function returns the maximum value.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 * @return Maximum value of the data set
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum value of the data set
 *
 * Given an array of data and a length, this function returns the minimum value.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 * @return Minimum value of the data set
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest
 *
 * Given an array of data and a length, this function sorts the array in descending order.
 *
 * @param array Pointer to the data array
 * @param length Length of the data array
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
