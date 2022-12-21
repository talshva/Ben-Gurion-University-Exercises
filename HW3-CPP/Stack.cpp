/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include <iostream>
#include "Stack.h"
using namespace std;

/* This class implements an ADT called 'Stack', which works exactly like an assault rifle stack -
First element in the stack is the last to come out and vice versa */

Stack::Stack()
{
   top = NULL;
}

void Stack:: push(int new_data) // Add new element to the top of the stack
{
   StackNode * newNode = new StackNode(new_data, top); //allocating memory for a new Node to be inserted
   top = newNode; //inserting the node on top.
}

void Stack:: pop() // remove the element at the top of the stack
{
   if(!isEmpty())
   {
      StackNode *p = top; // saving the adress of the top value in the stack
      cout << "Removing " << p->GetData() << endl;
      top = (top->GetNext()); //updating the new top to be the second item from the top
      delete(p);  // remove the previous top from the memory
   }  
   else cout << "Stack empty" << endl;
}

bool Stack:: isEmpty() const //return true if the stack is empty, and false otherwise.
{
   if(top == NULL) return true; 
   else return false;
}

int Stack:: peek() const // take a glimps on the value on top of the stack, without removing him.
{
   if(isEmpty()) return INT_MIN; //return the minimal possible int value if the stack is empty.
   else return top->GetData();
}

Stack::~Stack() // destructor
{
//*** Free all dynamic nodes in memory ***
   StackNode * temp;
   while (top!=NULL)
   {
      temp = top->GetNext();   
      delete(top);
      top = temp;   
   }
}

