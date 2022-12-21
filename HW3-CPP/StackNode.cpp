/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include <iostream>
#include "StackNode.h"

/* This class implements a single Node in the stack, where each node contains a value and a pointer
to a next node */


StackNode::StackNode():data(0),next(NULL){} // default constructor
StackNode:: StackNode(int datum ,StackNode* node):data(datum),next(node){}
int StackNode:: GetData() const //get function does not change any value (const)
{
	return data;
}

void StackNode:: SetNext(StackNode * node) // set a next node for our node
{
	next = node;
}

StackNode* StackNode:: GetNext() const	//get the next node of our node
{
	return next;
}

StackNode::~StackNode(){} //destructor
