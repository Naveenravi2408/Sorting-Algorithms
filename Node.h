/*
 * Node.h
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:

	Node();
	Node(Element element);

	Element element;

	Node *next;

};

#endif /* NODE_H_ */

