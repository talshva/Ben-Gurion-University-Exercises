/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include "DispenserType.h"
/* This class implements a single dispenser in the vending machine, used to store specific juice bottles */

DispenserType::DispenserType():cost(0),numberOfItems(0){} //default constructor
DispenserType::DispenserType(int items, int price):cost(price),numberOfItems(items){}
int DispenserType:: getNoOfItems() const //get function does not change any value.
{
	return numberOfItems; //returns the number of bottles in the dispenser
}
int DispenserType:: getCost() const
{
	return cost;   //return the price for each bottle in this dispenser
}
void DispenserType:: makeSale()
{
	numberOfItems -= 1; // remove one bottle from the dispenser
}
DispenserType::~DispenserType(){} //destructor
