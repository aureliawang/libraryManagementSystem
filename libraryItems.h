/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef libraryItems_h
#define libraryItems_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "libraryItems.h"
#include "libraryItem.h"

using namespace std;

//LibraryItems class definition

class LibraryItems {

//protected for inheritance
    protected:
       
       //declaring vector of Library Item pointers

       vector<LibraryItem *> itemList;
    
    public:
       
        //operator overloading function definition
	
        LibraryItems& operator<< (LibraryItem* item);
        
	//collection class function declarations
	
	void AddItem(LibraryItem* item);
        bool DeleteItem(int id);
        void DeleteItem();
        LibraryItem* FindItem(int id);
        int FindItemIndex(int id);
        void PrintAllItems();
        void PrintOneItem();
        void PrintItemByID(int id);
        void editItem();
    
	//constructor and destructor declarations
	
        LibraryItems();
        ~LibraryItems();
    
	//virtual function declarations
	
        virtual void LoadItems();
        virtual void StoreItems();
        
	//functions for code optimization
	
        bool isAvailable(int id);
        void checkout(int id);
};


#endif 

