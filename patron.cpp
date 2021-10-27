/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include "patron.h"
#include <iostream>
#include <vector>
//using namespace std;

//default constructor definition

Patron::Patron() {

    name = "";
    id = 0;
    fineBalance = 0.0;
    numCheckedOutBooks = 0;
    numOverdueBooks = 0;

}

//overloaded constructor definition

Patron::Patron(string name, int id, double fineBalance, int numCheckedOutBooks, int numOverdueBooks) {

    this->name = name;
    this->id = id;
    this->fineBalance = fineBalance;
    this->numCheckedOutBooks = numCheckedOutBooks;
    this->numOverdueBooks = numOverdueBooks;

}

//setter and getter method definitions

void Patron::setName(string name) {

    this->name = name;

}

string Patron::getName() {

    return name;

}

void Patron::setID(int id) {

    this->id = id;

}

int Patron::getID() {

    return id;

}

void Patron::setFineBalance(double fineBalance) {

    this->fineBalance = fineBalance;

}

double Patron::getFineBalance() {

    return fineBalance;

}

void Patron::setNumCheckedOutBooks(int numCheckedOutBooks) {

    this->numCheckedOutBooks = numCheckedOutBooks;

}

int Patron::getNumCheckedOutBooks() {

    return numCheckedOutBooks;

}

void Patron::setNumOverdueBooks(int numOverdueBooks) {

    this->numOverdueBooks = numOverdueBooks;

}

int Patron::getNumOverdueBooks() {

    return numOverdueBooks;

}



