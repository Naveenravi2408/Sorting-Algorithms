/*
 * ShellSortOptimal.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include "ShellSortOptimal.h"
#include <cmath>

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
	//http://www.stoimen.com/blog/2012/02/27/computer-algorithms-shell-sort/
	// (3^k - 1)/2
	int gap = 1, k=0;
	while(gap < size)
	{
		k++;
		gap = (pow(3,k) - 1)/2;
	}
	k = k-1;

	for(gap = gap-pow(3,k); gap > 0; gap = gap-pow(3,k))
		{
			for(int i = gap; i<size; i++)
			{
				Element temp = data[i];
				int j;

				for(j=i; ((j >= gap)&&(data[j - gap] > temp)); j = j-gap)
				{
						data[j] = data[j - gap];
						move_count++;
						compare_count++;
				}
				data[j] = temp;
				move_count++;
			}
			k--;
		}
}

