/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include <iostream>
#include "VendingMachine.h"
#include "DispenserType.h"
#include "CashRegister.h"
using namespace std;

/* This class implements a Vending Machine, which is capable of holding 3 kind of dispenser 
and a Cash register */

VendingMachine::VendingMachine():orange(10,45),carrot(5,50),pomegranate(4,75){} 
// empty constructor with 3 kind of default juices

void VendingMachine:: sellProduct(char c)
{
   // a function for selling a product from the vending machine
   int money; 
   int remainder;
   counter.setRegister(0);
   DispenserType * current_fruit; // create a temporary dispenser
   if (c == 'o')     current_fruit = &orange; // if user chose orange, the relevant dispenser is now orange.
   else if (c=='c')  current_fruit = &carrot; // same for carrot
   else         current_fruit = &pomegranate; // same for Rimon.
   if(current_fruit->getNoOfItems()>0) // if any juice bottle left in the chosen dispenser
   {
      cout << "Please deposit " << current_fruit->getCost() << " cents" << endl;
      cin >> money;
      counter.acceptAmount(money); // get some money from the user
      if(counter.getCurrentBalance() >= (current_fruit->getCost())) // if we paid more or same as asked
      {
         current_fruit->makeSale(); // get your refreshing juice.
         cout << "Collect your item at the bottom and enjoy." << endl;
         cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl; 
      }
      else
      {
         remainder = current_fruit->getCost() - counter.getCurrentBalance();  //calculate the money difference 
         cout << "Please deposit another " << remainder << " cents" << endl;  
         cin >> money;
         counter.acceptAmount(money);
         if(counter.getCurrentBalance() >= (current_fruit->getCost())) // if on the second try user paid enough money
         {
            current_fruit->makeSale();
            cout << "Collect your item at the bottom and enjoy." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;     
         }
         else // no juice for you.
         {
            cout << "The amount is not enough. Collect what you deposited." << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;    
         }
      }
   }
   else cout << "Sorry, this item is sold out." << endl; 
}
VendingMachine::~VendingMachine(){} // destructor
