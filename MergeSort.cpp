/*
 * MergeSort.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{

	//http://www.sanfoundry.com/cpp-program-implement-merge-sort-linked-list/
		LinkedList left;
		LinkedList right;

		if(list.get_head()->next == nullptr)
		{
			return;
		}
		else
		{
			list.split(left,right);

			mergesort(left);
			mergesort(right);

			merge(list, left, right);
		}

}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
	//http://www.sanfoundry.com/cpp-program-implement-merge-sort-linked-list/

	Node *left_node = sublist1.get_head();
	Node *right_node = sublist2.get_head();

	Node *t1 = new Node;
	Node *t2 = new Node;
	Node *temp = new Node;

	if(left_node == nullptr)
	{
		//list.tail = right_node;
		//list.concatenate(sublist2);
	}

	if(right_node == nullptr)
	{
		//list.tail = left_node;
		//list.concatenate(sublist1);
	}

	t1 = left_node;

	while(right_node != nullptr)
	{
		t2 = right_node;

		right_node = right_node->next;
		t2->next = nullptr;

		if(left_node->element.get_value() > t2->element.get_value())
		{
			t2->next = left_node;
			left_node = t2;
			t1 = left_node;
			continue;
		}

		flag:
		if(t1->next == nullptr)
		{
			t1->next = t2;
			t1 = t1->next;
		}

		else if((t1->next)->element.get_value() <= t2->element.get_value())
		{
			t1 = t1->next;
			goto flag;
		}

		else
		{
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}

	//list.tail = left_node;
	//list.concatenate(sublist1);

}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }


