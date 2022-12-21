/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include "DispenserType.h"
#include "CashRegister.h"

/* This class implements a Vending Machine, which is capable of holding 3 kind of dispenser 
and a Cash register */
/* more documentation on the cpp file */

class VendingMachine
{
   private:
      DispenserType orange;
      DispenserType carrot;
      DispenserType pomegranate;
      CashRegister counter;
   public:
      VendingMachine();
      void sellProduct(char);
      ~VendingMachine();
};

#endif