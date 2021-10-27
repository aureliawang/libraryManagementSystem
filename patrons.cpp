/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include "patrons.h"
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#define FILENAME "patronrecord.txt"
using namespace std;

//constructor defintion

Patrons::Patrons() {
    
    LoadPatrons();
    
}

//deconstructor definition

Patrons::~Patrons() {
    
    StorePatrons();
    
}

//add patron function definition

void Patrons::AddPatron() {

    string patronName;
    int id;
    
    cout << endl;

    cin.ignore();

    //prompt user for information of patron

    cout << "Name of Patron to add: ";
    getline(cin, patronName);

    //randomly generate ID number;
    
    srand(time(NULL));
    id = rand() % 900000 + 100000;

    cout << patronName << "\'s ID Number is " << id << endl;

    double fineBalance = 0.0;
    int numCheckedOutBooks = 0;
    int numOverdueBooks = 0;
    
    //create patron object and populate patron object

    Patron tempPatron(patronName, id, fineBalance, numCheckedOutBooks, numOverdueBooks);
   
    //add object to colection

    patronList.push_back(tempPatron);

}

//edit patron function definition

void Patrons::EditPatron() {

    int id;
    int userChoice;

    //prompt user for id of patron to edit

    cout << "ID number of the Patron to edit: ";
    cin >> id;

    //call Find Patron

    Patron* tempPatron = FindPatron(id);
    
    //if none return to main

    if(tempPatron == nullptr) {
        
        cout << "Patron not found" << endl;
        return;
        
    }
    
    do {
    
	//print out menu for user
	    
        cout << "Choose a number corresponding to attribute to edit: " << endl;
        cout << "1 - " << tempPatron->getName() << "\'s Name" << endl;
        cout << "2 - " << tempPatron->getName() << "\'s Fine Balance " << endl;
        cout << "3 - " << tempPatron->getName() << "\'s Number of Checked Out Books" << endl;
        cout << "4 - " << tempPatron->getName() << "\'s Number of Overdue Books" << endl;
        
        cout << "Attribute to edit: ";
        cin >> userChoice;

    } while((userChoice != 1) && (userChoice != 2) && (userChoice != 3) && (userChoice != 4) && (userChoice != 5) && (userChoice != 6));
    
    //based on user choice execute function

    switch(userChoice) {

        case 1: {

            cin.ignore();

            string newName;
            cout << "Enter Patron's new name: ";
            getline(cin, newName);

            tempPatron->setName(newName);
        }

            break;
        
        case 2: {

            double newFineBalance;
            cout << "Enter Patron's new fine balance: ";
            cin >> newFineBalance;

            tempPatron->setFineBalance(newFineBalance);

        }

            break;

        case 3: {

            int newNumCheckedOutBooks;
            cout << "Enter Patron's new number of checked out books: ";
            cin >> newNumCheckedOutBooks;
            
            tempPatron->setNumCheckedOutBooks(newNumCheckedOutBooks);

        }

            break;

        case 4: {

            int newNumOverdueBooks;
            cout << "Enter Patron's new number of overdue books: ";
            cin >> newNumOverdueBooks;
            
            tempPatron->setNumOverdueBooks(newNumOverdueBooks);

        }

            break;

    }

}

//delete patron function definition

void Patrons::DeletePatron() {

    //ask user for id of patron to delete

    int id;
    cout << "Enter Patron ID of Patron to delete: ";
    cin >> id;

    //iterate through patron list

    for(vector<Patron>::iterator iter = patronList.begin(); iter != patronList.end(); iter++) {

	//if patron matches delete at iterator position
        if(id == iter->getID()) {
            patronList.erase(iter);
            return;
        }
    }
    
    cout << "Patron ID not found" << endl;

}

//find patron function definition

Patron* Patrons::FindPatron(int id) {
    
    //iterate through patron list

    for(vector<Patron>::iterator iter = patronList.begin(); iter != patronList.end(); iter++) {

	//if match in ID return address of dereferenced iterator
        if(id == iter->getID()) {

            return &(*iter);
        }

    }
    
    return nullptr;

}

//find patron by index function definition

int Patrons::FindPatronIndex(int id) {

    for(unsigned int i = 0; i < patronList.size(); i++) {

        if(id == patronList.at(i).getID()) {

            return i;

        }

    }

    return -1;

}

//print all patrons

void Patrons::PrintAllPatrons() {

    int patronCount = 1;

    //iterate through patron list
    for(vector<Patron>::iterator iter = patronList.begin(); iter != patronList.end(); iter++) {
        
	//print out info in neat way for each patron
	
        cout << endl;
        cout << "Patron " << patronCount << ":" << endl;
        cout << "Name: " << iter->getName() << endl;
        cout << "ID Number: " << iter->getID() << endl;
        cout << "Fine Balance: " << iter->getFineBalance() << endl;
        cout << "Number of Checked Out Books: " << iter->getNumCheckedOutBooks() << endl;
        cout << "Number of Overdue Books: " << iter->getNumOverdueBooks() << endl;
        
        patronCount++;

    }

}

//print one patron

void Patrons::PrintOnePatron() {

    //Prompt user for ID number of Patron to print

    int id;
    cout << "Enter ID Number of Patron to print out: " << endl;
    cin >> id;

    //call function 

    PrintPatronByID(id);

}

//print patron by id

void Patrons::PrintPatronByID(int id) {

    //call find patron

    Patron* tempPatron = FindPatron(id);
   
    //if none, return to main

    if(tempPatron == nullptr) {
        
        cout << "Patron ID not found" << endl;
        
        return;
        
    } else {
     
	//else print information in a neat way
	
        cout << endl;

        cout << "Name: " << tempPatron->getName() << endl;
        cout << "ID Number: " << tempPatron->getID() << endl;
        cout << "Fine Balance: " << tempPatron->getFineBalance() << endl;
        cout << "Number of Checked Out Books: " << tempPatron->getNumCheckedOutBooks() << endl;
        cout << "Number of Overdue Books: " << tempPatron->getNumOverdueBooks() << endl;
    
    }
}

//pay fines

void Patrons::PayFines() {

    //Prompt user for ID number of Patron that is paying the fine

    int id;
    cout << "Enter ID Number of Patron to pay fines: " << endl;
    cin >> id;

    //Call Find Patron

    Patron* tempPatron = FindPatron(id);

    //Prompt user for the amount they want to pay

    double amountToPay;
    cout << "How much does this patron want to pay? " << endl;
    cin >> amountToPay;

    //Update Patron Fine Balance at that index by subtracting paid amount from fine

    tempPatron->setFineBalance(tempPatron->getFineBalance() - amountToPay);
    int prevNumOverdue = tempPatron->getNumOverdueBooks();
    tempPatron->setNumOverdueBooks(prevNumOverdue-1);

}

//loading patrons in

void Patrons::LoadPatrons() {

    ifstream fin;
    
    string name;
    int id;
    double fineBalance;
    int numCheckedOutBooks;
    int numOverdueBooks;

    //Open data file using macro

    fin.open(FILENAME);
    if (!fin.fail()) {
    
	//Loop through file:

        while(fin >> name >> id >> fineBalance >> numCheckedOutBooks >> numOverdueBooks) {

            //Read in information from data file and store in object

            replace(name.begin(), name.end(), '_', ' ');
            Patron tempPatron(name, id, fineBalance, numCheckedOutBooks, numOverdueBooks);
            patronList.push_back(tempPatron);

        }

	//close file
	
        fin.close();
        
    }

}

//store patrons

void Patrons::StorePatrons() {

    ofstream fout;

    //Open data file using macro

    fout.open(FILENAME);

    //Loop through collection:

    for(auto iter = patronList.begin(); iter != patronList.end(); iter++) {
        
	//Output formatted information into data file 

        string name = iter->getName();
        replace(name.begin(), name.end(), ' ', '_');
        fout << name << ' ' << iter->getID() <<' ' << iter->getFineBalance() <<' ' << iter->getNumCheckedOutBooks() <<' ' << iter->getNumOverdueBooks() << endl;

    }

    fout.close();

}

//check borrown elligibility

bool Patrons::allowBorrow(int pid)
{
    //loop thorugh collection	
    for(vector<Patron>::iterator iter = patronList.begin(); iter != patronList.end(); iter++) {

	    //id match
        if(pid == iter->getID() ) {
            
		//f number of overdue books is 0 and number of checked out books is 5

	    if (iter->getNumOverdueBooks() == 0 && iter->getNumCheckedOutBooks() <= 5) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

//change checkout

void Patrons::checkout(int pid){

	//Iterate through patronList

   	for(vector<Patron>::iterator iter = patronList.begin(); iter != patronList.end(); iter++) {

	//If ID matches and if status of book is in, change to out

	if(pid == iter->getID() ) {
            iter->setNumCheckedOutBooks(iter->getNumCheckedOutBooks() + 1);
        }
    }
}


