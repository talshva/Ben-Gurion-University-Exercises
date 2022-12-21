/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include "CashRegister.h"
/* This class implements a cash register that deals purchases, money insertion and currrent balance */
CashRegister::CashRegister():cashOnHands(0){} //default constructor
CashRegister::CashRegister(int CashInput)     //constructor with additional money input
{
   cashOnHands = CashInput;   
}
int CashRegister::getCurrentBalance() const     // all of 'get' functions will not change during the program.
{
   return cashOnHands; 
}
void CashRegister::acceptAmount(int amountInput){
   cashOnHands += amountInput;      //add money to the register
}
void CashRegister::setRegister(int CashInput)
{
   cashOnHands = CashInput;   //set amount of money, used later on to clear the cash register on new purchase.
}
CashRegister::~CashRegister(){} //destructor
