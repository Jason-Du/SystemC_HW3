#include <iostream>
#include "List.h"
#include <assert.h>
#include <cstddef> 
#include <stdio.h>
using namespace std;

List::List():Node()
{
	length=0;
}
List::List(unsigned int _length):Node(_length)
{
	
	length=_length;
}


List::List(const List& other)
{
	length = other.length;
	if (other.length > 0)
	{
		_Node=new long int[length];
		assert(_Node!= 0);
		for (unsigned int i= 0; i< length; i++)
		{
			_Node[i] = *(other._Node+i);
		}
	}
	else
	{
		_Node=NULL;
		length=0;
	}
}


List::~List()
{
	if (length!=0) 
	{
		length=0;
	}
}




/*

} If the original length is 0, the function sets a new length, uses
reCreate() to allocates an array of size length to _Node,
then returns 1.
} If the original length is not 0, the function prints an error
message then returns 0.
*/

int List::setLength(unsigned int _length)
{
	if(length==0)
	{
		_Node=reCreate(_length);
		length=_length;
		return 1;
	}
	else
	{
		 printf("ERROR ! array length is not 0");
		 return 0;
	}
	
}

unsigned int List::getLength()
{
	return length;
}
int List::setElement(unsigned int pos, long val)
{
	if (pos>length)
	{
		printf("ERROR! pos is not legal;");
		return 1;
	}
	else
		
	{	
		*(_Node+pos)=val;
		return 0;
	}
}
long int List::getElement(unsigned int pos)
{
	if (pos>length)
	{
		printf("ERROR! pos is not legal;");
		return -99999;
	}
	else
	{	
		return*(_Node+pos);
	}

}

/*// Assignment operator
◦ List operator+(const List &);
◦ List& operator+=(const List &);
◦ List operator++();
◦ List operator++(long);
◦ List operator--();
◦ List operator--(long);
◦ friend ostream& operator<<(ostream &, List);
◦ friend istream& operator>>(istream, List &);
*/

// Assignment operator

List& List::operator=(const List& other)
{
	if (this != &other) 
	{ // if the same one, do nothing
		delete [] _Node;
		length=other.length;
		if (length > 0)
		{
			_Node=new long int[length];
			//delete [] _Node; // _Node may not be NULL
			assert(_Node != 0);
			for (unsigned int i= 0; i< length; i++)
			{
				_Node[i]= other._Node[i];
			}
		}
		else
		{
			_Node = NULL;
			length=0;
		}
	}
	return *this; // return this object
}
List List::operator+(const List &other) {
    unsigned int loop =length< other.length ? length:other.length;
    // create a return object is required
    List lt(loop);
    for (unsigned int i = 0; i < loop; i++) 
	{
        lt._Node[i] = _Node[i] + other._Node[i];
	}
    return lt;
}
List List::operator+=(const List &other) {
    unsigned int loop =length < other.length ? length:other.length;
    for (unsigned int i = 0; i < loop; i++) {
        _Node[i] += other._Node[i];
	}
    return *this;
}
List List::operator++() {
    for (unsigned int i = 0; i < length; i++) {
        ++_Node[i];  // prefix ++
	}
    return *this;
}
List List::operator++(int) {
    List tmp(*this);   // Retain a copy first
    for (unsigned int i = 0; i < length; i++) {
        _Node[i]++;   // postfix++
	}
    return tmp;
}
List List::operator--() {
    for (unsigned int i = 0; i < length; i++) {
        --_Node[i];  // prefix ++
	}
    return *this;
}
List List::operator--(int) {
    List tmp(*this);   // Retain a copy first
    for (unsigned int i = 0; i < length; i++) 
	{
        _Node[i]--;   // postfix++
	}
    return tmp;
}

ostream& operator<<(ostream &out, List list) {
    for (unsigned int i = 0; i < list.length; i++)
        out << list._Node[i] <<"";
    out << endl;
    return out;
}
istream& operator>>(istream &in, List &list) {
    for (unsigned int i = 0; i < list.length; i++)
        in >> list._Node[i];
    return in;
}









