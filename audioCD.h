/* Aurelia Wang
 * CSCE1040.001
 * Homework 4
 */

#ifndef audioCD_h
#define audioCD_h

#include <stdio.h>
#include <string>
#include "libraryItem.h"
using namespace std;

//inheritance

class AudioCD : public LibraryItem {

	//private attribute declarations

    private:
        
        string artist;
        string title;
        int trackNum;
        string releaseDate;
        string genre;

    public:

		//default and parameterized constructor declaration

        AudioCD();
        AudioCD(int id, double cost, LibraryItemStatus currStatus, int loanPeriod, string title, string artist, int trackNum, string releaseDate, string genre);

		//setter and getter function declarations

        void setTitle(string title);
        string getTitle();
        void setArtist(string artist);
        string getArtist();
        void setTrackNum(int trackNum);
        int getTrackNum();
        void setReleaseDate(string releaseDate);
        string getReleaseDate();
        void setGenre(string releaseDate);
        string getGenre();

	//virtual function definitions (inherited from base class)
	
        virtual void printItem() override;
        virtual void editItem() override;
        virtual LibraryItemType getType() override;
        virtual void storeItemToFile(ofstream &os) override;

	//creating items from either UI or file for code optimization

	static AudioCD* CreateItemFromFile(ifstream &fin);
        static AudioCD* CreateItemFromUI();
};

#endif

