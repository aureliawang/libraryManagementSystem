/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <iostream>
#include "patrons.h"
#include "libraryItems.h"
#include "book.h"
#include "audioCD.h"
#include "loans.h"
#include "dvd.h"

void PatronMenu(Patrons* patrons);
void LibraryItemMenu(LibraryItems* books);
void LoanMenu(Loans *loans);
void addItemMenu(LibraryItems *items);

int main() {

    LibraryItems items = LibraryItems();
    Patrons patrons = Patrons();
    Loans loans = Loans(&patrons, &items);
    
    char userChoice;
    
    //root menu
    while (true) {
        cout << "Hello! Would you like to work on Patrons, Books, or Loans?" << endl;
        cout << "Enter P for Patrons" << endl;
        cout << "Enter B for Library Items" << endl;
        cout << "Enter L for Loans" << endl;
        cout << "Enter Q to Quit" << endl;
        
        cout << "---> ";
        cin >> userChoice;
        
        switch(userChoice) {
                
            case 'P': {
                PatronMenu(&patrons);
            }
                break;
            
            case 'B': {
                LibraryItemMenu(&items);
            }
                break;
                
            case 'L': {
                LoanMenu(&loans);
            }
                
                break;
                
            case 'Q': {
                
                cout << "Thank you for using our library!" << endl;
                
                return 0;
                
            }
                
                break;
                
            default:
                
                cout << "Please choose a valid letter from the menu" << endl;
                
                break;
                
        }

    }
    
    return 0;
}

void PatronMenu(Patrons* patrons) {
    
    char userChoice;

    while (true) {
        
        cout << endl;
                
        cout << "Choose a letter corresponding to an option you would like to do for Patron" << endl;
        cout << "A - Add a Patron" << endl;
        cout << "E - Edit a Patron" << endl;
        cout << "D - Delete a Patron" << endl;
        cout << "P - Print All Patrons" << endl;
        cout << "O - Print One Patron" << endl;
        cout << "F - Pay Fines" << endl;
        cout << "B - Go Back to Upper Menu" << endl;
        
        cout << "---> ";
        cin >> userChoice;
        
        switch(userChoice) {
                
            case 'A': {
                
                patrons->AddPatron();
            
            }
                
                break;
            
            case 'E': {
                
                patrons->EditPatron();
                
            }
                
                break;
                
            case 'D': {
                
                patrons->DeletePatron();
                
            }
                
                break;
                
            case 'P': {
                
                patrons->PrintAllPatrons();
                            
            }
                
                break;
                
            case 'O': {
                
                patrons->PrintOnePatron();
            
            }
                
                break;
                
            case 'F': {
                
                patrons->PayFines();
                
            }
                
                break;
                
            case 'B': {
                
                cout << endl;
                
                return;
                
            }
                
                break;
                
            default: {
                
                cout << "Please choose a valid letter from the menu" << endl;
                
            }
                
                break;
                
        }
        
    }
    
}

void addItemMenu(LibraryItems *items) {
    char userChoice;

    while (true) {
        
        cout << endl;
        
        cout << "Choose a letter corresponding to a type you would like to add for a library item" << endl;
        cout << "O - Add a Book" << endl;
        cout << "A - Add a Audio CD" << endl;
        cout << "D - Add a DVD" << endl;
        cout << "B - Go Back to Upper Menu" << endl;
        
        cout << "---> ";
        cin >> userChoice;
        
        switch(userChoice) {
            case 'O': {
                items->AddItem(Book::CreateItemFromUI());
                
            }
                
                break;
                
            case 'A': {
                items->AddItem(AudioCD::CreateItemFromUI());
              
            }
                
                break;

            case 'D': {
                
                items->AddItem(Dvd::CreateItemFromUI());
                
            }
                
                break;
            
            case 'B': {
                
                cout << endl;
                
                return;
                
            }
                
            default: {
                
                cout << "Please choose a valid letter from the menu" << endl;
                
            }
                
                break;
        }
     }
}


void LibraryItemMenu(LibraryItems *items) {
    
    char userChoice;

    while (true) {
        
        cout << endl;
        
        cout << "Choose a letter corresponding to an option you would like to do for a library item" << endl;
        cout << "A - Add a item" << endl;
        cout << "E - Edit a item" << endl;
        cout << "D - Delete a item" << endl;
        cout << "P - Print All items" << endl;
        cout << "O - Print One item" << endl;
        cout << "B - Go Back to Upper Menu" << endl;
        
        cout << "---> ";
        cin >> userChoice;
        
        switch(userChoice) {
                
            case 'A': {
                
                addItemMenu(items);
                
            }
                
                break;
            
            case 'E': {
                
                items->editItem();
                
            }
                
                break;
                
            case 'D': {
                
                items->DeleteItem();
                
            }
                
                break;
                
            case 'P': {
                
                items->PrintAllItems();
                            
            }
                
                break;
                
            case 'O': {
                
                items->PrintOneItem();
            
            }
                
                break;
                
            case 'B': {
                
                cout << endl;
                
                return;
                
            }
                
                break;
                
            default: {
                
                cout << "Please choose a valid letter from the menu" << endl;
                
            }
                
                break;
                
        }
        
    }
    
}

void LoanMenu(Loans *loans) {
    
    char userChoice;

    while (true) {
                
        cout << endl;
        
        cout << "Choose a letter corresponding to an option you would like to do for Book" << endl;
        cout << "I - Check In Item" << endl;
        cout << "O - Check Out Item" << endl;
        cout << "A - List All Overdue With Patron Info" << endl;
        cout << "U - Update All Overdue Status" << endl;
        cout << "P - Print Items For One Patron" << endl;
        cout << "E - Edit Loan" << endl;
        cout << "R - Recheck Item" << endl;
        cout << "L - Report Lost" << endl;
        cout << "B - Go Back to Upper Menu" << endl;
        
        cout << "---> ";
        cin >> userChoice;
        
        switch(userChoice) {
                
            case 'I': {
                
                loans->checkin();
                
            }
                
                break;
            
            case 'O': {
                
                loans->checkout();
                
            }
                
                break;
                
            case 'A': {
                
                loans->listAllOverdue();
                                
            }
                
                break;
                
            case 'U': {
                
                loans->updateAlloverdueStatus();
                
            }
            
                break;
                
            case 'P': {
                
                loans->printBooksForOnePatron();
                
            }
                
                break;
                
            case 'E': {
                
                loans->EditLoan();
                
            }
                
                break;
                
            case 'R': {
                
                loans->RecheckBook();
                
            }
                
                break;
                
            case 'L': {
                
                loans->ReportLost();
                
            }
                
                break;
                
            case 'B': {
                
                cout << endl;
                return;
                
            }
                
            default: {
                
                cout << "Please choose a valid letter from the menu" << endl;
                
            }
                
                break;
                
        }
        
    }
    
    
}


