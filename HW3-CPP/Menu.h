/* Assignment C++: 1
Authors: Tal Shvartzberg , ID: 316581537
		   Roi Osman       , ID: 319022265
*/ 


#ifndef MENU_H
#define MENU_H

/* This class implements a Menu object, that contains 2 sub-menus for the user*/
/* First menu is for the Juice Shop, Second menu for an ADT type called 'stack' */
/* more documentation on the cpp file */
class Menu
{
   private:
   public:
      Menu();
      void mainMenu();
      void shopMenu();
      void stackMenu();
      ~Menu();
};

#endif