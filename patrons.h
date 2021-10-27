/* Aurelia Wang
 * CSCE1040.001
 * Homework 3
 */

#ifndef patrons_h
#define patrons_h

#include <iostream>
#include <vector>
#include <string>
#include "patron.h"

using namespace std;

//patrons class definition

class Patrons {

    private:

        vector<Patron> patronList;
   // string replaceStrChar(string str, const string& replace, char ch);
    
    public:

	//constructor and method declarations
	
        Patrons();
        ~Patrons();

        void AddPatron();
        void EditPatron();
        void DeletePatron();
        Patron* FindPatron(int id);
        int FindPatronIndex(int id);
        void PrintAllPatrons();
        void PrintOnePatron();
        void PrintPatronByID(int id);
        void PayFines();
        void LoadPatrons();
        void StorePatrons();
    
        bool allowBorrow(int pid);
        void checkout(int pid);
};

#endif

