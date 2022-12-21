/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <climits>
#include "StackNode.h"

/* This class implements an ADT called 'Stack', which works exactly like an assault rifle stack -
First element in the stack is the last to come out and vice versa */
/* more documentation on the cpp file */

class Stack
{
   private:
      StackNode * top;
   public:
      Stack();
      void push(int);
      void pop();
      bool isEmpty() const;
      int peek() const;
      ~Stack();
};

#endif