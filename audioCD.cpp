/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#include <algorithm>
#include "audioCD.h"
#define loanperiodindays 10

//default constructor definition

AudioCD::AudioCD() {

    title = "";
    artist = "";
    trackNum = 0;
    releaseDate = "";
    genre = "";

}

//parameterized constructor definition

AudioCD::AudioCD(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string artist, int trackNum, string releaseDate, string genre) : LibraryItem(id, cost, currStatus, loanPeriod) {

    this->title = title;
    this->artist= artist;
    this->trackNum = trackNum;
    this->releaseDate = releaseDate;
    this->genre =genre;

}

AudioCD* AudioCD::CreateItemFromFile(ifstream &fin) {
    string artist;
    string title;
    int trackNum;
    int id;
    double cost;
    string releaseDate;
    string genre;
    int loanPeriod;
    int currStatus;

    //read in from file
    
    fin >> artist >> title >> trackNum >> id >> cost >> currStatus >> releaseDate >> genre >> loanPeriod;
    replace(artist.begin(), artist.end(), '_', ' ');
    replace(title.begin(), title.end(), '_', ' ');

    //return newly created object

    return new AudioCD(id, cost,(LibraryItemStatus) currStatus, loanPeriod, title, artist, trackNum, releaseDate, genre);
}

AudioCD* AudioCD::CreateItemFromUI() {
    string title;
    string authorName;
    int trackNum;
    int id;
    double bookCost;
    string releaseDate;
    string genre;
    LibraryItemStatus currStatus;
    
    cout << endl;
    
    cin.ignore();

    //prompt user for book info

    cout << "Name of Artist of AudioCD to add: ";
    getline(cin, authorName);

    cout << "Title of AudioCD to add: ";
    getline(cin, title);

    cout << "Track number of AudioCD to add: ";
    cin >> trackNum;
    
    cin.ignore();
    
    cout << "Release date of Audio CD to add: ";
    getline(cin, releaseDate);

    cout << "Genre of Audio CD to add: ";
    getline(cin, genre);
    
    //randomly generate ID number;
    
    srand(time(NULL));
    id = rand() % 900000 + 100000;

    cout << title << "\'s Library ID Number is " << id << endl;

    cout << "Cost of Audio CD: ";
    cin >> bookCost;

    currStatus = In;

    //return newly created object

    return new AudioCD(id, bookCost, (LibraryItemStatus) currStatus, loanperiodindays, title, authorName, trackNum, releaseDate, genre);
}

void AudioCD::storeItemToFile(ofstream &os)
{
    string artist = getArtist();
    string title = getTitle();

    replace(artist.begin(), artist.end(), ' ', '_');
    replace(title.begin(), title.end(), ' ', '_');
    
    //output everything into file in a neat way

    os << artist << " " << title << " " << getTrackNum() << " " << getId() << " " << getCost() << " " <<  getCurrStatus() << " " << getReleaseDate() << " " << getGenre() << " " << getLoanPeriod();
}

//getter and setter function definitions

void AudioCD::setTitle(string title) {

    AudioCD::title = title;

}

string AudioCD::getTitle() {

    return title;

}

void AudioCD::setArtist(string artist) {

    AudioCD::artist = artist;

}

string AudioCD::getArtist() {

    return artist;

}

void AudioCD::setTrackNum(int trackNum) {

    AudioCD::trackNum = trackNum;

}

int AudioCD::getTrackNum() {

    return trackNum;

}

void AudioCD::setReleaseDate(string releaseDate) {

    AudioCD::releaseDate = releaseDate;

}

string AudioCD::getReleaseDate() {

    return releaseDate;

}

void AudioCD::setGenre(string genre)
{
    AudioCD::genre = genre;
}

string AudioCD::getGenre()
{
    return genre;
}


LibraryItemType AudioCD::getType() {
    return AudioType;
}

void AudioCD::printItem() {

    //call base class to print its info

    LibraryItem::printItem();
    
    //print book specific info

    cout << "Artist: " << getArtist() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Track Number: " << getTrackNum() << endl;
    cout << "Release Date: " << getReleaseDate() << endl;
    cout << "Genre: " << getGenre() << endl;
}

void AudioCD::editItem() {
        int userChoice;
        cout << endl;
        
        do {
            
            cout << endl;

	    //print menu and read in user choice

            cout << "Choose a number corresponding to attribute to edit: " << endl;
            cout << "1 - " << getTitle() << "\'s Artist" << endl;
            cout << "2 - " << getTitle() << "\'s Title" << endl;
            cout << "3 - " << getTitle() << "\'s track number" << endl;
            cout << "4 - " << getTitle() << "\'s Cost" << endl;
            cout << "5 - " << getTitle() << "\'s Current Status" << endl;
            cout << "6 - " << getTitle() << "\'s Genre" << endl;
            cout << "7 - " << getTitle() << "\'s release Date" << endl;

            cout << "---> ";
            cin >> userChoice;
        
        } while (userChoice<1 || userChoice >7);

	//change using corresponding function to what user wants to change

        switch(userChoice) {

            case 1: {

                cin.ignore();

                string newAuthor;
                cout << "Enter AudoCD's new artist: ";
                getline(cin, newAuthor);

                setArtist(newAuthor);

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

                cout << "Enter Book's new track number: ";
                cin >> newTrackNumber;

                setTrackNum(newTrackNumber);

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
                cout << "Enter AudioCD's new Genre: ";
                getline(cin, newTitle);

                setGenre(newTitle);

            }
                break;
                
            case 7: {

                cin.ignore();

                string newTitle;
                cout << "Enter AudioCD's new Release Date: ";
                getline(cin, newTitle);

                setReleaseDate(newTitle);

            }
                break;
        }
    }

