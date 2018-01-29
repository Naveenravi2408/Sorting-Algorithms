/*
 * Element.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    value = other.value;
    copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

long Element::get_copy_count()
{
	return copy_count;
}


long Element::get_destructor_count()
{
	return destructor_count;
}


void Element::reset()
{
	copy_count = 0;
	destructor_count = 0;
}

bool operator == (Element& first_ele, Element& second_ele)
{
	if(first_ele.value == second_ele.value)
	{
		return true;
	}

	else return false;
}

bool operator < (const Element& first_ele, const Element& second_ele)
{
	if(first_ele.value < second_ele.value)
	{
		return true;
	}

	else return false;
}


bool operator >(const Element& first_ele, const Element& second_ele)
{
	if(first_ele.value > second_ele.value)
	{
		return true;
	}

	else return false;
}


ostream& operator<<(ostream& outs, const Element& ele)
{
	outs << ele.get_value();
	return outs;
}
