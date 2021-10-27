/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef loan_h
#define loan_h

#include <stdio.h>
#include <ctime>
#include <string>

//class Loan definition

class Loan {

    //private attributes declaration
    
    private:
   
    int loanID;
    int bookID;
    int patronID;
    int recheckCount;
    time_t dueDateTime;
    bool overdue;
    
    public:
    
    //constructors and setter and getter method declarations

    Loan( int bookId, int patronId, int loanId, int recheckCount);
    Loan();
    
    int getLoanID();
    void setLoanID(int loanID);
    
    int getBookID();
    void setBookID(int bookID);
    
    int getPatronID();
    void setPatronID(int patronID);
        
    int overdueIndays();
    void listAllOverdue();
    
    int getRecheckCount();
    void setRecheckCount(int recheckCount);
    
    std::string getDueDate();
    void setDueDate(std::string dateStr);
    
    bool getOverdue();
    void setOverdue(bool overdue);
    
    void recheckout();
};

#endif
