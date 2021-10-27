/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef libraryItem_h
#define libraryItem_h

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//defining enum for status of library item

enum LibraryItemStatus {
    In = 0,
    Out,
    Repair,
    Lost
};

//defining enum for type of library item

enum LibraryItemType {
    BookType = 0,
    AudioType,
    DVDType
};

//LibraryItem class definition

class LibraryItem {

    //protected accessor for inheritance subclasses

    protected:

	//variable declaration
	
        int id;
        double cost;
        LibraryItemStatus currStatus;
        double loanPeriod;

    public:
        
	//contructor (default and parameterized) and virtual destructor declarations
	
        LibraryItem();
        virtual ~LibraryItem();
	LibraryItem(int id, double cost, LibraryItemStatus currStatus, double loanPeriod);
        
	//setter and getter function declarations
	
        void setId(int id);
        int getId();
        void setCost(double cost);
        double getCost();
        void setCurrStatus(LibraryItemStatus currStatus);
        LibraryItemStatus getCurrStatus();
        void setLoanPeriod(double loanPeriod);
        double getLoanPeriod();
        
	//virtual and pure virtual function declarations
	
        virtual void printItem();
        virtual void editItem() = 0;
        virtual LibraryItemType getType() = 0;
        virtual void storeItemToFile(ofstream &os) = 0;
};
#endif 

