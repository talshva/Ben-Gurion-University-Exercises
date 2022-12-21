/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#include <iostream>
#include "Menu.h"
#include "VendingMachine.h"
#include "Stack.h"
using namespace std;

/* This class implements a Menu object, that contains 2 sub-menus for the user*/
/* First menu is for the Juice Shop, Second menu for an ADT type called 'stack' */

Menu::Menu(){}
void Menu:: mainMenu()
{
  int input1;
  do
  {
    cout << "(1) Fresh juice Shop" << endl;
    cout << "(2) Integer Stack" << endl;
    cout << "(3) Exit" << endl;
    cin >> input1;
    switch (input1)    // choosing the function to be executed, according to the input value.
    {
      case 1:
      shopMenu(); 
      break;
      case 2:
      stackMenu(); 
      break;
      case 3:
      cout << "Goodbye!" << endl;
      break;  
      default:   
      cout << "Invalid selection." << endl;
      break;    
    }
  }
  while (input1!=3);
}
void Menu:: shopMenu()
{
  VendingMachine Shop;   
  int input2;   
  do
  {
    cout << "*** Welcome to juice Shop ***" << endl;
    cout << "To select an item, enter" << endl;
    cout << "1 For Orange juice" << endl;
    cout << "2 For Carrot juice" << endl;
    cout << "3 For Pomegranate" << endl;
    cout << "4 To exit" << endl;
    cin >> input2;

    switch (input2)  // choosing the function to be executed, according to the input value.
    {
      case 1:
      Shop.sellProduct('o');  //user chose to buy orange juice
      break;
      case 2:
      Shop.sellProduct('c');  //user chose to buy carrot juice
      break;
      case 3:
      Shop.sellProduct('p');  //user choose to buy pomegrante juice
      break;
      case 4:
      cout << "Thank you!" << endl;
      break;   
      default: 
      cout << "Invalid selection." << endl;  
      break;    
    }
  }
  while (input2!=4);
}

//second sub-menu for the implemention of the Stack Data type.
void Menu:: stackMenu()
{
  Stack integer_stack;   
  int input3;   
  int el;
  int first;
  bool empty;
  do
  {
    cout << "*** Manage your integer stack ***" << endl;
    cout << "1 Push new element" << endl;
    cout << "2 Pop element" << endl;
    cout << "3 Show the first element" << endl;
    cout << "4 Check if empty" << endl;
    cout << "5 to exit" << endl;
    cin >> input3;
    switch (input3)    // choosing the function to be executed, according to the input value.
    {
      case 1:
      cout << "Please insert the new element: ";
      cin >> el;
      integer_stack.push(el); // Add new element to the top of the stack
      break;
      case 2:
      integer_stack.pop();  // remove the element at the top of the stack
      break;
      case 3:
      first = integer_stack.peek(); // take a glimps on the value on top of the stack, without removing him.
      cout << "The first element is: " << first << endl;
      break;
      case 4:
      empty = integer_stack.isEmpty(); //return true if the stack is empty, and false otherwise.
      if (empty) cout << "The stack is empty" << endl;
      else cout << "The stack is not empty" << endl;
      break;
      case 5:
      cout << "Thank you!" << endl;
      break;
      default:   
      cout << "Invalid selection." << endl;
      break;    
    }
  }
  while (input3!=5);
} // *** program calling the destructor for the "Stack" object ***

Menu::~Menu(){}
