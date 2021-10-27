/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef patron_h
#define patron_h

#include <string>
using namespace std;

//patron class definition

class Patron {

//private members declaration

    private:
        
        string name;
        int id;
        double fineBalance;
        int numCheckedOutBooks;
        int numOverdueBooks;

    public:

//constructors and setter and getter method declarations

        Patron();
        Patron(string name, int id, double fineBalance, int numCheckedOutBooks, int numOverdueBooks);

        void setName(string name);
        string getName();
        void setID(int id);
        int getID();
        void setFineBalance(double fineBalance);
        double getFineBalance();
        void setNumCheckedOutBooks(int numCheckedOutBooks);
        int getNumCheckedOutBooks();
        void setNumOverdueBooks(int numOverdueBooks);
        int getNumOverdueBooks();

};

#endif

