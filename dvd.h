/* Aurelia Wang
 * CSCE1040.001
 * Homework 3
 */

#ifndef dvd_h
#define dvd_h

#include <string>
#include "libraryItem.h"
using namespace std;

//inheritance

class Dvd : public LibraryItem {

    //private attribute declarations

    private:
        string category;
        string title;
        int runTime;
        string releaseDate;
        string studio;

    public:

	//default and parameterized constructor declaration

        Dvd();
        Dvd(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string category, int runTime, string releaseDate, string studio);

	//setter and getter function declarations

        void setTitle(string title);
        string getTitle();
        void setCategory(string category);
        string getCateglory();
        void setRuntime(int runtime);
        int getRuntime();
        void setReleaseDate(string releaseDate);
        string getReleaseDate();
        void setStudio(string releaseDate);
        string getStudio();

	//virtual function definitions (inherited from base class)
	
        virtual void printItem() override;
        virtual void editItem() override;
        virtual LibraryItemType getType() override;
        virtual void storeItemToFile(ofstream &os) override;

	//creating items from either UI or file for code optimization

	static Dvd* CreateItemFromFile(ifstream &fin);
        static Dvd* CreateItemFromUI();
};

#endif 

