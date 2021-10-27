/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <algorithm>
#include "dvd.h"
#define loanperiodindays 10

//default constructor definition

Dvd::Dvd() {
    
    title = "";
    category = "";
    runTime = 0;
    releaseDate = "";
    studio = "";

}

//parameterized constructor definition

Dvd::Dvd(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string category, int runTime, string releaseDate, string studio) : LibraryItem(id, cost, currStatus, loanPeriod)

{
    this->title = title;
    this->category= category;
    this->runTime = runTime;
    this->releaseDate = releaseDate;
    this->studio = studio;

}

Dvd* Dvd::CreateItemFromFile(ifstream &fin) {
    string category;
    string title;
    int runTime;
    int id;
    double cost;
    string releaseDate;
    string studio;
    int loanPeriod;
    int currStatus;

    //read in from file
    
    fin >> category >> title >> runTime >> id >> cost >> currStatus >> releaseDate >> studio >> loanPeriod;
    replace(title.begin(), title.end(), '_', ' ');

    //return newly created object

    return new Dvd( id,  cost, (LibraryItemStatus) currStatus,  loanPeriod,  title,  category,  runTime,  releaseDate,  studio);

}

Dvd* Dvd::CreateItemFromUI() {
    string title;
    string category;
    int runTime;
    int id;
    double bookCost;
    string releaseDate;
    string studio;
    LibraryItemStatus currStatus;
    
    cout << endl;
    
    cin.ignore();

    //prompt user for dvd info

    cout << "Category of DVD to add: ";
    getline(cin, category);

    cout << "Title of Dvd to add: ";
    getline(cin, title);

    cout << "Run Time of DVD to add (minutes): ";
    cin >> runTime;
    
    cin.ignore();
    
    cout << "Release date of Audio CD to add: ";
    getline(cin, releaseDate);

    cout << "Studio of DVD to add: ";
    getline(cin, studio);
    
    //randomly generate ID number;
    
    srand(time(NULL));
    id = rand() % 900000 + 100000;

    cout << title << "\'s Library ID Number is " << id << endl;

    cout << "Cost of DVD: ";
    cin >> bookCost;

    currStatus = In;

        //return newly created object

    return new Dvd(id,  bookCost, (LibraryItemStatus) currStatus,  loanperiodindays,  title,  category,  runTime,  releaseDate,  studio);
}

void Dvd::storeItemToFile(ofstream &os)
{
    string category = getCateglory();
    string title = getTitle();

    replace(title.begin(), title.end(), ' ', '_');

    //output everything into file in a neat way
    
    os << category << " " << title << " " << getRuntime() << " " << getId() << " " << getCost() << " " <<  getCurrStatus() << " " << getReleaseDate() << " " << getStudio() << " " << getLoanPeriod();
}

//getter and setter function definitions

void Dvd::setTitle(string title) {

    Dvd::title = title;

}

string Dvd::getTitle() {

    return title;

}

void Dvd::setCategory(string category) {

    this->category = category;

}

string Dvd::getCateglory() {

    return category;

}

void Dvd::setRuntime(int runtime) {

    this->runTime = runTime;

}

int Dvd::getRuntime() {

    return runTime;

}

void Dvd::setReleaseDate(string releaseDate) {

    this->releaseDate = releaseDate;

}

string Dvd::getReleaseDate() {

    return releaseDate;

}

void Dvd::setStudio(string studio)
{
    this->studio = studio;
}

string Dvd::getStudio()
{
    return studio;
}


LibraryItemType Dvd::getType() {
    return DVDType;
}

void Dvd::printItem() {

    //call base class to print its info

    LibraryItem::printItem();
    
    //print dvd specific info
	    
    cout << "Category: " << getCateglory() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Run Time: " << getRuntime() << endl;
    cout << "Release Date: " << getReleaseDate() << endl;
    cout << "Studio: " << getStudio() << endl;
}

void Dvd::editItem() {
        int userChoice;
        cout << endl;
        
        do {
            
            cout << endl;

 	    //print menu and read in user choice

            cout << "Choose a number corresponding to attribute to edit: " << endl;
            cout << "1 - " << getTitle() << "\'s Category" << endl;
            cout << "2 - " << getTitle() << "\'s Title" << endl;
            cout << "3 - " << getTitle() << "\'s run time" << endl;
            cout << "4 - " << getTitle() << "\'s Cost" << endl;
            cout << "5 - " << getTitle() << "\'s Current Status" << endl;
            cout << "6 - " << getTitle() << "\'s Studio" << endl;
            cout << "7 - " << getTitle() << "\'s release Date" << endl;

            cout << "---> ";
            cin >> userChoice;
        
        } while (userChoice<1 || userChoice >7);

	//change using corresponding function to what user wants to change

        switch(userChoice) {

            case 1: {

                cin.ignore();

                string newAuthor;
                cout << "Enter AudoCD's new category: ";
                getline(cin, newAuthor);

                setCategory(newAuthor);

            }

                break;

            case 2: {

                cin.ignore();

                string newTitle;
                cout << "Enter AudoCD's new title: ";
                getline(cin, newTitle);

                setTitle(newTitle);

            }

                break;

            case 3: {
                
                int newTrackNumber;

                cout << "Enter Dvd's new run time: ";
                cin >> newTrackNumber;

                setRuntime(newTrackNumber);

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
                
            case 6: {

                cin.ignore();

                string newTitle;
                cout << "Enter Dvd's new studio: ";
                getline(cin, newTitle);

                setStudio(newTitle);

            }
                break;
                
            case 7: {

                cin.ignore();

                string newTitle;
                cout << "Enter AudoCD's new Release Date: ";
                getline(cin, newTitle);

                setReleaseDate(newTitle);

            }
                break;
        }
    }

