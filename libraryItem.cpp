/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include "libraryItem.h"

//default constructor definition

LibraryItem::LibraryItem() {

    LibraryItem::id = 0;
    LibraryItem::cost = 0.0;
    LibraryItem::currStatus = In;
    LibraryItem::loanPeriod = 0;

}

//destructor definition

LibraryItem::~LibraryItem() {
    
}

//overloaded constructor definition

LibraryItem::LibraryItem(int id, double cost, LibraryItemStatus currStatus, double loanPeriod) {

    LibraryItem::id = id;
    LibraryItem::cost = cost;
    LibraryItem::currStatus = currStatus;
    LibraryItem::loanPeriod = loanPeriod;

}

//setter and getter function definitions

void LibraryItem::setId(int id) {
    
    LibraryItem::id = id;

}

int LibraryItem::getId() {

    return id;

}

void LibraryItem::setCost(double cost) {

    LibraryItem::cost = cost;

}

double LibraryItem::getCost() {

    return cost;

}

void LibraryItem::setCurrStatus(LibraryItemStatus currStatus) {

    LibraryItem::currStatus = currStatus;

}

LibraryItemStatus LibraryItem::getCurrStatus() {

    return currStatus;

}

void LibraryItem::setLoanPeriod(double loanPeriod) {

    LibraryItem::loanPeriod = loanPeriod;

}

double LibraryItem::getLoanPeriod() {

    return loanPeriod;

}

//printing library items using base class

void LibraryItem::printItem() {
        cout << endl;
        cout << "Library ID: " << getId() << endl;
        cout << "Cost: " <<  getCost() << endl;
        cout << "Loan Period: " << getLoanPeriod() << endl;
        string statusStr;

	//find current status of library item with getCurrStatus()
	
	switch (getCurrStatus()) {
            case 0:
                statusStr = "In";
                break;
                
            case 1:
                statusStr = "Out";
                break;
            case 2:
                statusStr = "Repair";
                break;
                
            case 3:
                statusStr = "Lost";
                break;
                
            default:
                statusStr = "Unknown";
                break;
        }

	//print current status
	
        cout << "Current Status: " <<  statusStr << endl;
    
}

