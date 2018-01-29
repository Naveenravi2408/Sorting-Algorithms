/*
 * Element.h
 *
 *  Created on: Nov 12, 2017
 *      Author: navee
 */

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    static void reset();
    static long get_copy_count();
    static long get_destructor_count();

    friend bool operator ==(Element& first_ele, Element& second_ele);
    friend bool operator < (const Element& first_ele, const Element& second_ele);
    friend bool operator > (const Element& first_ele, const Element& second_ele);

    friend ostream& operator <<(ostream& outs, const Element& ele);


private:
    long value;
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */

