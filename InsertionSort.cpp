/*
 * InsertionSort.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
	//http://www.geeksforgeeks.org/insertion-sort/
	   int i, j;
	   Element key;

	   for(i=1; i<size; i++)
	   {
		   key = data[i];
		   j = i-1;

		   while((j >= 0) && (data[j] > key))
		   {
			   data[j+1] = data[j];
			   j = j-1;
			   move_count++;
			   compare_count++;
		   }
		   data[j+1] = key;
		   move_count++;
	   }
}


