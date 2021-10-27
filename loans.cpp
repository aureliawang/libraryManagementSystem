/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include "loans.h"
#include <sstream>
#define FINERATE 0.25
#define FILENAME "loanrecord.txt"

//constructor definition

Loans::Loans(Patrons* ps, LibraryItems* bs)
{
    patrons = ps;
    books = bs;
    maxId = 0;
  
    //load loanlist from a file
    
    LoadLoans();
    
}

//deconstructor definition

Loans::~Loans() {

    //store loans

    StoreLoans();
    
}

void Loans::checkout()
{
    int pid;
    int bid;
  
    //prompt user for ids
  
    cout << "Patron ID of Patron who wants to check out item: ";
    cin >> pid;
    
    cout << "Library ID of item to check out: ";
    cin >> bid;
    
    //if user and book meets elligibility then check out book, add to loan, and give user a unique loan id
    
    if (patrons->allowBorrow(pid) && books->isAvailable(bid) ) {
        maxId++;
        cout << "Your Loan ID is " << maxId << endl;
        Loan loan = Loan(bid, pid, maxId, 0);
        loanList.push_back(loan);
        books->checkout(bid);
        patrons->checkout(pid);
        
    } else {
    
	//if no id found or error
	//print error message
	    
        cout << "Checkout Failed. Please check inputted IDs, availability of item, and Patron's eligibility to check out a item again." << endl;
        
    }
    
}

void Loans::checkin() {
    
    int pid;
    int bid;
    
    //prompt user for ids

    cout << "Patron ID of Patron checking in a item: ";
    cin >> pid;
    
    cout << "Library ID of Item being checked in: ";
    cin >> bid;
    Loan *loan = findLoan(bid, pid);
    if (loan == nullptr) {
  
   	//error message if not existing

        cout << "Valid loan not found!" <<endl;
        return;
    }
    
        //if overdue, tell user

    if(loan->overdueIndays() > 0) {
        
        cout << "Item is overdue so you owe fines. Go pay first." << endl;
        Patron* tempPatron = patrons->FindPatron(pid);
        tempPatron->setFineBalance(loan->overdueIndays() * FINERATE);
        
    } else {
 
	 //if not overude, remove the loan and decrement num of checked out books for user

        removeLoan(loan);
        Patron* tempPatron = patrons->FindPatron(pid);
        int prevNumCheckedOut = tempPatron->getNumCheckedOutBooks();
        tempPatron->setNumCheckedOutBooks(prevNumCheckedOut - 1);
        
    }
    
        //change status to in

    books->FindItem(bid)->setCurrStatus(In);
}


Loan* Loans::findLoan(int bid, int pid) {

        //iterate through loan list
	
    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {

    	//match in id    
	    
        if(iter->getBookID() == bid && iter->getPatronID() == pid) {

    	//return address of dereferenced iterator position
		
            return &(*iter);
            
        }
    }
    
    return nullptr;
}

void Loans::removeLoan(Loan* loan) {
    vector<Loan>::iterator iter2;

        //iterate through; if match, store and delete after

    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {
        if (&(*iter) == loan) {
            iter2 = iter;
            break;
        }
    }
    loanList.erase(iter2);
}


void Loans::listAllOverdue() {
    
    updateAlloverdueStatus();

    //iterate through and print for each book and patron id that matches with loan's data

    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {
        
        if(iter->getOverdue()) {
            books->PrintItemByID(iter->getBookID());
            patrons->PrintPatronByID(iter->getPatronID());
            
        }
    }
}

void Loans::updateAlloverdueStatus() {
   
  //iterate through
  //calculate fine rate if overdue
  //assign fine rate
  //increment user overduebook count by 1
	
    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {
        if(iter->overdueIndays() > 0) {
            patrons->FindPatron(iter->getPatronID())->setFineBalance(iter->overdueIndays() * FINERATE);
            int prevOverdue = patrons->FindPatron(iter->getPatronID())->getNumOverdueBooks();
            patrons->FindPatron(iter->getPatronID())->setNumOverdueBooks(prevOverdue+1);
        }

    }
}

void Loans::printBooksForOnePatron() {
    
    int patronID;
  
        //prompt user for patron id
  
    cout << "Patron ID whose items are to be listed: ";
    cin >> patronID;

    //iterate through
    
    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {
        
        if(iter->getPatronID() == patronID) {

	    //if match, print book by id with print book by id function
		
            int tempBookID = iter->getBookID();
            books->PrintItemByID(tempBookID);
            
        }
    }
    
}

void Loans::EditLoan() {
    
    int loanID;
    int userChoice;

    //ask user for loan id
    
    cout << "Enter Loan ID of Loan to Edit: " << endl;
    cin >> loanID;
    
    Loan* tempLoan = FindLoanByLoanID(loanID);

    //if no loan, return to main
    
    if(tempLoan == nullptr) {
        
        cout << "Loan ID not found" << endl;
        return;
        
    }
    
    do {

    //print menu

        cout << "Choose a number corresponding to attribute to edit: " << endl;
        cout << "1 - " << "Due Date and Time" << endl;
        cout << "2 - " << "Recheck Count" << endl;
    
    //user input

        cout << "Attribute to edit: ";
        cin >> userChoice;

    } while((userChoice != 1) && (userChoice != 2) && (userChoice != 3));
    
    //based on case, execute

    switch(userChoice) {

        case 1: {

            cin.ignore();

            string newDueDateAndTime;
            cout << "Enter New Due Date and Time (mm/dd/yy): ";
            cin >> newDueDateAndTime;

            tempLoan->setDueDate(newDueDateAndTime);
            
        }

            break;
        
        case 2: {

            int newRecheckCount;
            cout << "Enter New Recheck Count: ";
            cin >> newRecheckCount;
            
            tempLoan->setRecheckCount(newRecheckCount);

        }

            break;
            
    }

}

void Loans::RecheckBook() {
    
    int patronID;
    int bookID;
    
    //prompt user for ids

    cout << "Patron ID that is renewing the item: ";
    cin >> patronID;
    
    cout << "Item ID being renewed: ";
    cin >> bookID;

    //call find book
    
    Loan* tempLoan = findLoan(bookID, patronID);

    //if no book, tell user and return to main
    
    if(tempLoan == nullptr) {
        
        cout << "Loan not Found" << endl;
        return;
        
    }

    //call recheckout
    
    
    tempLoan->recheckout();
    
}

void Loans::ReportLost() {
    
    int loanID;

    //prompt for loan id

    cout << "Loan ID of lost item: ";
    cin >> loanID;

    //call findloanbyloanid
    
    Loan* tempLoan = FindLoanByLoanID(loanID);

    //update cost and fine balance
    
    Patron *tempPatron = patrons->FindPatron(tempLoan->getPatronID());
    double balance = tempPatron->getFineBalance();
    balance += books->FindItem(tempLoan->getBookID())->getCost();
    tempPatron->setFineBalance(balance);

    //delete loan
    
    removeLoan(tempLoan);
    
}


Loan* Loans::FindLoanByLoanID(int id) {

	    //iterate through

    for(vector<Loan>::iterator iter = loanList.begin(); iter != loanList.end(); iter++) {

	    	    //if match, return dereferenced iterator address

        if(id == iter->getLoanID()) {
        
            return &(*iter);

        }

    }

    return nullptr;

}

void Loans::LoadLoans() {

    ifstream fin;

    int loanID;
    int bookID;
    int patronID;
    string dueDateTime;
    int recheckCount;

        //open file using macro

    fin.open(FILENAME);
    if (! fin.fail()) {

	    	    //while data to read in, create and populate loan object

       while(fin >> bookID >> patronID >> loanID >> recheckCount) {
            tm timeInfo;
            string timestr;
            fin >> timestr;
//            std::istringstream ss(timestr);
//            ss >> std::get_time(&timeInfo, "%m/%d/%y");
//
//            timeInfo.tm_hour = 0;
//            timeInfo.tm_min = 0;
//            timeInfo.tm_sec = 0;
            Loan tempLoan = Loan(bookID, patronID, loanID, recheckCount);
            tempLoan.setDueDate(timestr);
       
	    	    //add object to collection

       	    loanList.push_back(tempLoan);

        }

       //close file

        fin.close();
    }

}

void Loans::StoreLoans() {

    ofstream fout;
    string fileName;

    //open file using macro

    fout.open(FILENAME);

    //iterate through
    
    for(auto iter = loanList.begin(); iter != loanList.end(); iter++) {
        string dueDate = iter->getDueDate();
//        tm *timeInfo = localtime(&cotime);
         fout << iter->getBookID() << " " << iter->getPatronID() << " " << iter->getLoanID() << " " << iter->getRecheckCount()<<" ";
//        char tstr[10];
//        strftime(tstr, 10, "%D", timeInfo);
        fout << dueDate << endl;
    }

    //close file

    fout.close();

}

