/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <sstream>
#include <ctime>
#include <locale>
#include <iomanip>
#include "loan.h"

#define loanperiodindays 10

//default constructor definition

Loan::Loan() {
    
    overdue = false;
    bookID = 0;
    patronID = 0;
    loanID = 0;
    recheckCount = 0;
    time_t rawTime;
    time(&rawTime);
    tm *tminfo = localtime(&rawTime);
    tminfo->tm_mday += loanperiodindays;
    dueDateTime = mktime(tminfo);
    
}

//overloaded constructor definition

Loan::Loan(int bookId, int patronId, int loanId, int recheckCount)
{
    overdue = false;
    this->bookID = bookId;
    this->patronID = patronId;
    this->loanID = loanId;
    this->recheckCount = recheckCount;
    this->dueDateTime = time(&dueDateTime);
}

//setter and getter method definitions

int Loan::getLoanID() {
    
    return loanID;
    
}

void Loan::setLoanID(int loanID) {
    
    this->loanID = loanID;
    
}

int Loan::getBookID() {
    
    return bookID;
    
}

void Loan::setBookID(int bookID) {
    
    this->bookID = bookID;
    
}

int Loan::getPatronID() {
    
    return patronID;
    
}

void Loan::setPatronID(int patronID) {
    
    this->patronID = patronID;
    
}

int Loan::getRecheckCount() {
    
    return recheckCount;
    
}

void Loan::setRecheckCount(int recheckCount) {
    
    this->recheckCount = recheckCount;
    
}

//getting how much item overdue in days

int Loan::overdueIndays() {
    time_t currenttime;
    time(&currenttime);
    
    double diffinseconds = difftime(currenttime, this->dueDateTime);
    int diffIndays = diffinseconds / 86400;
    if (diffIndays > 0) {
        overdue = true;
        return  diffIndays;
    }
    else {
        overdue = false;
        return 0;
    }
}

//get item due date

std::string Loan::getDueDate()
{
    tm *timeInfo = localtime(&this->dueDateTime);
    char tstr[10];
    strftime(tstr, 10, "%D", timeInfo);
    return tstr;
}

//set due date

void Loan::setDueDate(std::string dateStr)
{
    tm timeInfo;
    std::istringstream ss(dateStr);
    ss >> std::get_time(&timeInfo, "%m/%d/%y");
    
    timeInfo.tm_hour = 0;
    timeInfo.tm_min = 0;
    timeInfo.tm_sec = 0;
    this->dueDateTime = mktime(&timeInfo);
}

bool Loan::getOverdue()
{
    return this->overdue;
}
void Loan::setOverdue(bool overdue)
{
    this->overdue = overdue;
}

//recheck out item

void Loan::recheckout() {
    time_t rawTime;
    time(&rawTime);
    tm *tminfo = localtime(&rawTime);
    tminfo->tm_mday += loanperiodindays;
    dueDateTime = mktime(tminfo);
    
    recheckCount++;
}

