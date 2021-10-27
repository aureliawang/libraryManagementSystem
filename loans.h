/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef loans_h
#define loans_h

#include <stdio.h>
#include "loan.h"
#include "patrons.h"
#include "libraryItems.h"

//Loans class definition

class Loans {

    //private members declaration

    private:
    
    vector<Loan> loanList;
    Patrons* patrons;
    LibraryItems*   books;
    int maxId;
    void LoadLoans();
    void StoreLoans();
    
    public:
    
    //constructor and deconstructor and function declarations

    Loans(Patrons* ps, LibraryItems* bs);
    ~Loans();
    
    void checkout();
    void checkin();
    Loan* findLoan(int bid, int pid);
    void listAllOverdue();
    void updateAlloverdueStatus();
    void removeLoan(Loan* loan);
    void printBooksForOnePatron();
    void EditLoan();
    Loan* FindLoanByLoanID(int id);
    void RecheckBook();
    void ReportLost();
    
};

#endif
