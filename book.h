/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef book_h
#define book_h

#include <string>
#include "libraryItem.h"
using namespace std;

//inheritance

class Book : public LibraryItem {

	//private attribute declarations
	
    private:
        
        string author;
        string title;
        int ISBN;
        string category;

    public:

	//default and parameterized constructor declaration
	
        Book();
        Book(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string author, int ISBN, string category);

	//setter and getter function declarations
	
        void setTitle(string title);
        string getTitle();
        void setAuthor(string author);
        string getAuthor();
        void setISBN(int ISBN);
        int getISBN();
        void setCategory(string category);
        string getCategory();
        
	//virtual function definitions (inherited from base class)
	
        virtual void printItem() override;
        virtual void editItem() override;
        virtual LibraryItemType getType() override;
        virtual void storeItemToFile(ofstream &os) override;
        
	//creating items from either UI or file for code optimization
	
	static Book* CreateItemFromFile(ifstream &fin);
        static Book* CreateItemFromUI();
};

#endif

