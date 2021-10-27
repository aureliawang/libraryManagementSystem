/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include "libraryItems.h"
#include "book.h"
#include "audioCD.h"
#include "dvd.h"

#define FILENAME "LibaryItemrecord.txt"

using namespace std;

//constructor and destructor definitions

LibraryItems::LibraryItems() {
    LoadItems();
}

LibraryItems::~LibraryItems() {
    StoreItems();
}

void LibraryItems::LoadItems() {

    ifstream fin;

    //open file using macro

    fin.open(FILENAME);
    if (!fin.fail()) {
        int type;

	//while data to read in, create and populate loan object

    	while(fin >> type) {
            LibraryItem *item;
            switch (type) {
                case BookType:
                    item = Book::CreateItemFromFile(fin);
                    break;
                case AudioType:
                    item = AudioCD::CreateItemFromFile(fin);
                    break;
                case DVDType:
                    item = Dvd::CreateItemFromFile(fin);
                    break;
                default:
                    break;
            }

	    //add object to collection

	    (*this) << item;
	}

	//close file

	fin.close();
        
    }

}

void LibraryItems::StoreItems() {

    ofstream fout;

    //open file using macro

    fout.open(FILENAME);

    //iterate through itemList

    for(auto iter = itemList.begin(); iter != itemList.end(); iter++) {
        LibraryItem *item = *iter;
    
    	//output info in neat way 

    	fout << item->getType() << " ";
        item->storeItemToFile(fout);
        fout << endl;
    }

    //close file

    fout.close();

}

//operator overloading

LibraryItems& LibraryItems::operator<< (LibraryItem* item) {

    //Add Item using AddItem

    AddItem(item);

    //Return address of self

    return *this;
}

void LibraryItems::AddItem(LibraryItem* item) { 
   //push back item
   itemList.push_back(item);
}

bool LibraryItems::DeleteItem(int id) {
    //iterate through
    for(vector<LibraryItem *>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {

	//if ID match
        if(id == (*iter)->getId()) {
            itemList.erase(iter);
            //delete dereferenced iterator
	    delete(*iter);
            return true;
        }
    }
    
    return false;
}

void LibraryItems::DeleteItem() {

    int id;
    //prompt user for id
    cout << "Enter Library ID of item to delete: ";
    cin >> id;
    if (!DeleteItem(id)) {

	//if item not found, print error message
        cout << "Library ID not found" << endl;
    }
    
}


LibraryItem* LibraryItems::FindItem(int id) {

	//iterate through
    for(vector<LibraryItem *>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {

	    //if match in id, return dereferenced iterator
        if(id == (*iter)->getId()) {
        
            return *iter;

        }

    }

    return nullptr;

}

int LibraryItems::FindItemIndex(int id) {

	//loop through and return index if found
	
    for(unsigned int i = 0; i < itemList.size(); i++) {

        if(id == itemList.at(i)->getId()) {

            return i;

        }

    }

    //not found
    return -1;

}

void LibraryItems::PrintAllItems() {

    int count = 1;

    //iterate through and call print item by id for each item using the id

    for(vector<LibraryItem *>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {
        PrintItemByID((*iter)->getId());
        count++;
        cout << endl;
    }

}

void LibraryItems::PrintOneItem() {

    int id;
    //prompt user for id
    cout << "Enter ID number of Library Item to print out: " << endl;
    cin >> id;

    //call print item by id

    PrintItemByID(id);

}

void LibraryItems::editItem()
{
    int id;

    cout << endl;
    
    //prompt user for id
    cout << "Library ID of Item to edit: ";
    cin >> id;

    //call find id
    LibraryItem* item = FindItem(id);
    
    //error message if not found
    if (item == nullptr ) {
        cout << "Book Library ID not found" << endl;
        return;
    }
    
    //call edit item 
    item->editItem();
}


bool LibraryItems::isAvailable(int id)
{

	//iterate through
    for(auto iter = itemList.begin(); iter != itemList.end(); iter++) {
        
	//if id match and its in, return true
	//if match and its out, return false
	if ((*iter)->getId() ==  id) {
            if ((*iter)->getCurrStatus() == In) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

void LibraryItems::checkout(int id)
{
	//iterate through and if id match and if item is in, set current status to out
	
    for(auto iter = itemList.begin(); iter != itemList.end(); iter++) {
        if ((*iter)->getId() ==  id && (*iter)->getCurrStatus() == In ) {
            (*iter)->setCurrStatus(Out);
        }
    }
}

void LibraryItems::PrintItemByID(int id) {
    
	//call find item
	
    LibraryItem* tempItem = (LibraryItem *) FindItem(id);
    
    cout << endl;
    
    //error message if not found

    if(tempItem == nullptr) {
        cout << "Library ID is not found" << endl;
        return;
        
    } else {
        
	//find type and print it out
	
	LibraryItemType type = tempItem->getType();
        switch (type) {
            case BookType:
                cout << "Book";
            break;
            case AudioType:
                cout << "AudioCD";
            break;
            case DVDType:
                cout << "DVD";
            break;
                
            default:
                break;
        }
        cout <<endl;
        //print out found item's info
	tempItem->printItem();
    }
}


