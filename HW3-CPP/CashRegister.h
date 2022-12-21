/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#ifndef CASHREGISTER_H
#define CASHREGISTER_H

/* This class implements a cash register that deals purchases, money insertion and currrent balance */
/* more documentation on the cpp file */
class CashRegister
{
   private:
      int cashOnHands;
   public:
      CashRegister();
      CashRegister(int);
      void setRegister(int);
      int getCurrentBalance() const;
      void acceptAmount(int);
      ~CashRegister();
};

#endif