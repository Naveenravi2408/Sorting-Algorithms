/*
 * ShellSortSuboptimal.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
	//http://www.geeksforgeeks.org/shellsort/
	for(int gap = size/2; gap > 0; gap = gap/2)
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
	}
}


