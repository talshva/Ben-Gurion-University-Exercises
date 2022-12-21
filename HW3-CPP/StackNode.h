/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>

/* This class implements a single Node in the stack, where each node contains a value and a pointer
to a next node */
/* more documentation on the cpp file */

class StackNode
{
   private:
      int const data;
      StackNode * next;
   public:
      StackNode();
      StackNode(int,StackNode*);
      int GetData() const;
      void SetNext(StackNode *);
      StackNode* GetNext() const;
      ~StackNode();

};
#endif