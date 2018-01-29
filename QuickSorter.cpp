/*
 * QuickSorter.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
	//http://www.geeksforgeeks.org/quick-sort/
	if(left < right)
	{
		Element& pivot = choose_pivot(left,right);
		int partition_index = partition(left, right, pivot);

		quicksort(left, partition_index - 1);
		quicksort(partition_index + 1, right);
	}
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	//http://www.geeksforgeeks.org/quick-sort/

	int i = (left - 1);

	for(int j = left; j <= right - 1; j++)
	{
		if(data[j].get_value() <= pivot.get_value())
		{
			i++;
			compare_count++;
			swap(i,j);
		}
	}
	swap(i+1, right);
	return (i+1);
}


