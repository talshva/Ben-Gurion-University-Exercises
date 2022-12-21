/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 

#ifndef DISPENSERTYPE_H
#define DISPENSERTYPE_H
/* This class implements a single dispenser in the vending machine, used to store specific juice bottles */
/* more documentation on the cpp file */

class DispenserType
{
   private:
      int numberOfItems;
      int const cost;
   public:
      DispenserType();
      DispenserType(int numberOfItems, int cost);
      int getNoOfItems() const;
      int getCost() const;
      void makeSale();
      ~DispenserType();
};

#endif
