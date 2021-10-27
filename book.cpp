/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <algorithm>
#include "book.h"
#define loanperiodindays 10

//default constructor definition

Book::Book() {

    Book::title = "";
    Book::author = "";
    Book::ISBN = 0;
    Book::category = "";

}

//parameterized constructor definition

Book::Book(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string author, int ISBN, string category) : LibraryItem(id, cost, currStatus, loanPeriod) {

    Book::title = title;
    Book::author = author;
    Book::ISBN = ISBN;
    Book::category = category;

}

Book* Book::CreateItemFromFile(ifstream &fin) {
    string author;
    string title;
    int ISBN;
    int id;
    double cost;
    string category;
    int loanPeriod;
    int currStatus;

    //read in from file

    fin >> author >> title >> ISBN >> id >> cost >> currStatus >> category >> loanPeriod;
    replace(author.begin(), author.end(), '_', ' ');
    replace(title.begin(), title.end(), '_', ' ');
    
    //return newly created object

    return new Book(id, cost, (LibraryItemStatus)currStatus, loanPeriod, title, author, ISBN, category);
}

Book* Book:: CreateItemFromUI()
{
    string bookName;
    string authorName;
    int ISBN;
    int id;
    double bookCost;
    string category;
    LibraryItemStatus currStatus;
    
    cout << endl;
    
    cin.ignore();

    //prompt user for book info

    cout << "Name of Author of Book to add: ";
    getline(cin, authorName);

    cout << "Name of Book to add: ";
    getline(cin, bookName);

    cout << "ISBN of Book to add: ";
    cin >> ISBN;
    
    cin.ignore();
    
    cout << "Category of Book to add: ";
    getline(cin, category);

    //randomly generate ID number;
    
    srand(time(NULL));
    id = rand() % 900000 + 100000;

    cout << bookName << "\'s Library ID Number is " << id << endl;

    cout << "Cost of Book: ";
    cin >> bookCost;

    currStatus = In;

    //return newly created object

    return new Book(id, bookCost, currStatus, loanperiodindays, bookName, authorName, ISBN, category);
}


void Book::storeItemToFile(ofstream &os)
{
    string author = getAuthor();
    string title = getTitle();

    replace(author.begin(), author.end(), ' ', '_');
    replace(title.begin(), title.end(), ' ', '_');
    
    //output everything into file in a neat way

    os << author << " " << title << " " << getISBN() << " " << getId() << " " << getCost() << " " <<  getCurrStatus() << " " << getCategory() << " " << getLoanPeriod();
}

//getter and setter function definitions

void Book::setTitle(string title) {

    Book::title = title;

}

string Book::getTitle() {

    return title;

}

void Book::setAuthor(string author) {

    Book::author = author;

}

string Book::getAuthor() {

    return author;

}

void Book::setISBN(int ISBN) {

    Book::ISBN = ISBN;

}

int Book::getISBN() {

    return ISBN;

}

void Book::setCategory(string category) {

    Book::category = category;

}

string Book::getCategory() {

    return category;

}

LibraryItemType Book::getType() {
    return BookType;
}

void Book::printItem() {

    //call base class to print its info
    LibraryItem::printItem();
    //print book specific info
    cout << "Author: " << getAuthor() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "ISBN: " << getISBN() << endl;
}

void Book::editItem() {
        int userChoice;
        cout << endl;
        
        do {
            
            cout << endl;
	    //print menu and read in user choice

            cout << "Choose a number corresponding to attribute to edit: " << endl;
            cout << "1 - " << getTitle() << "\'s Author" << endl;
            cout << "2 - " << getTitle() << "\'s Title" << endl;
            cout << "3 - " << getTitle() << "\'s ISBN" << endl;
            cout << "4 - " << getTitle() << "\'s Cost" << endl;
            cout << "5 - " << getTitle() << "\'s Current Status" << endl;

            cout << "---> ";
            cin >> userChoice;
        
        } while ((userChoice != 1) && (userChoice != 2) && (userChoice != 3) && (userChoice != 4) && (userChoice != 5) && (userChoice != 6));

	//change using corresponding function to what user wants to change
	
        switch(userChoice) {

            case 1: {

                cin.ignore();

                string newAuthor;
                cout << "Enter Book's new author: ";
                getline(cin, newAuthor);

                setAuthor(newAuthor);

            }

                break;

            case 2: {

                cin.ignore();

                string newTitle;
                cout << "Enter Book's new title: ";
                getline(cin, newTitle);

                setTitle(newTitle);

            }

                break;

            case 3: {
                
                int newISBN;

                cout << "Enter Book's new ISBN: ";
                cin >> newISBN;

                setISBN(newISBN);

            }

                break;

            case 4: {

                double newCost;
                
                cout << "Enter Book's new Cost: ";
                cin >> newCost;

                setCost(newCost);

            }

                break;

            case 5: {

                cin.ignore();

                int newStatus;

		//another menu for status

                while(true) {
                    cout << "Enter Book's new Status: "<< endl;
                    cout << "0 - In" << endl;
                    cout << "1 - Out" << endl;
                    cout << "2 - Repair" << endl;
                    cout << "3 - Lost" << endl;
                    cout << "---> ";
                    cin >> newStatus;
                    if (newStatus >= 0 && newStatus <=3) {
                        break;
                    }
                }

                setCurrStatus((LibraryItemStatus)newStatus);
            }
                break;
        }
    }

