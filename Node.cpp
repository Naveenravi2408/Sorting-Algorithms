/*
 * Node.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include "Node.h"
#include "Element.h"

Node::Node()
{
	next = nullptr;
}

Node::Node(Element in_element)
{
	element = in_element;
	next = nullptr;
}


