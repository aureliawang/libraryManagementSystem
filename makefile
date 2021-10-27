Library: main.o patron.o loan.o libraryItem.o book.o audioCD.o dvd.o patrons.o loans.o libraryItems.o
	g++ -o Library main.o patron.o loan.o libraryItem.o book.o audioCD.o dvd.o patrons.o loans.o libraryItems.o

main.o: main.cpp patron.h loan.h libraryItem.h book.h audioCD.h dvd.h patrons.h loans.h libraryItems.h
	g++ -c main.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

libraryItem.o: libraryItem.cpp libraryItem.h
	g++ -c libraryItem.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

audioCD.o: audioCD.cpp audioCD.h
	g++ -c audioCD.cpp

dvd.o: dvd.cpp dvd.h
	g++ -c dvd.cpp

patrons.o: patrons.cpp patron.h
	g++ -c patrons.cpp

loans.o: loans.cpp loan.h
	g++ -c loans.cpp

libraryItems.o: libraryItems.cpp libraryItems.h
	g++ -c libraryItems.cpp

clean:
	rm Library *.o

run:
	make && ./Library
