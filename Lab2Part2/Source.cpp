#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//All the getters and setters need to find the necessary information 
class bookType
{
private:
	string title;
	string authors[4];
	string ISBN;
	int years;
	double price;
	string publisher;
	int numOfCopies;
	int numOfAuthors;

public:
	void setTitle(string _setTitle)
	{
		title = _setTitle;
	}
	void setAuthor(string name, int index)
	{
		authors[index] = name;
	}
	void setISBN(string _setISBN)
	{
		ISBN = _setISBN;
	}
	void setYears(int _years)
	{
		years = _years;
	}
	void setPrice(double _price)
	{
		price = _price;
	}
	void setPublisher(string _publisher)
	{
		publisher = _publisher;
	}
	void setNumOfCopies(int _numOfCopies)
	{
		numOfCopies = _numOfCopies;
	}
	void setNumOfAuthors(int _numOfAuthors)
	{
		numOfAuthors = _numOfAuthors;
	}
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		string str;
		for (int i = 0; i < numOfAuthors; i++)
		{
			str = str + authors[i] + " ";
		}
		return str;

	}
	string getISBN()
	{
		return ISBN;
	}
	int getYears()
	{
		return years;
	}
	double getPrice()
	{
		return price;
	}
	string getPublisher()
	{
		return publisher;
	}
	int getNumOfCopies()
	{
		return numOfCopies;
	}
	int getNumOfAuthors()
	{
		return numOfAuthors;
	}
};

void getBookData(bookType books[], int& numOfBooks);
void printBookData(bookType books[], int numOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount,
	string ISBN, int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title,
	int& loc);
void updateCopiesInStock(bookType books[], int bookCount);


int main()
{

	bookType  books[100];
	int numOfBooks;



	getBookData(books, numOfBooks);
	int choice;
	cout << "1. Print data " << endl;
	cout << "2. Search data " << endl;
	cout << "3. Update " << endl;

	cin >> choice;
	if (choice == 1)
	{
		printBookData(books, numOfBooks);
	}
	else if (choice == 2)
	{
		searchBookData(books, numOfBooks);

	}
	else
	{
		if (choice == 3)
		{
			updateCopiesInStock(books, numOfBooks);
		}
	}



}


//Getting the information needed for the program
void getBookData(bookType books[], int& numOfBooks)
{
	string title;
	string authors[4];
	string ISBN;
	int years;
	double price;
	string publisher;
	int numOfCopies;
	int numOfAuthors;
	string str;
	ifstream infile;
	infile.open("book.dat", ios::in);
	infile >> numOfBooks;
	infile.ignore();

	//For loop to grab the information from the book.dat file
	for (int i = 0; i <numOfBooks; i++)
	{
		getline(infile, title);
		books[i].setTitle(title);
		getline(infile, ISBN);
		books[i].setISBN(ISBN);
		getline(infile, publisher);
		books[i].setPublisher(publisher);
		infile >> years;
		books[i].setYears(years);
		infile >> price;
		books[i].setPrice(price);
		infile >> numOfCopies;
		books[i].setNumOfCopies(numOfCopies);
		infile >> numOfAuthors;
		books[i].setNumOfAuthors(numOfAuthors);
		infile.ignore();

		for (int j = 0; j < numOfAuthors; j++)
		{

			getline(infile, str);
			books[j].setAuthor(str, j);
		}






	}



}

//To print out the data on the screen 
void printBookData(bookType books[], int numOfBooks)
{
	for (int i = 0; i < numOfBooks; i++)
	{

		cout << books[i].getTitle() << endl;
		cout << books[i].getISBN() << endl;
		cout << books[i].getYears() << endl;
		cout << books[i].getPrice() << endl;
		cout << books[i].getPublisher() << endl;
		cout << books[i].getNumOfCopies() << endl;
		cout << books[i].getNumOfAuthors() << endl;
	}

}

//Searches the file for books by specific inputs
void searchBookData(bookType books[], int bookCount)
{
	int selection;
	string ISBN;
	string title;
	int loc;
	int input;

	cout << "1. Search by ISBN " << endl;
	cout << "2. Search by Title" << endl;
	cin >> selection;

	if (selection == 1)
	{
		cout << "Please input ISBN: " << endl;
		cin >> input;
		searchBookDataByISBN(books, bookCount, ISBN, loc);
	}
	else
	{
		cout << "Please input Book Title" << endl;
		cin >> input;
		searchBookDataByTitle(books, bookCount, title, loc);
	}

}

//Searches the file for books with their ISBN
//Could not really figure out how to make this work
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN, int & loc)
{

	loc = -1;
	ifstream infile;
	infile.open("book.dat", ios::in);
	infile >> bookCount;
	infile.ignore();

	for (int i = 0; i < bookCount; i++)
	{

		getline(infile, ISBN);
		books[i].setISBN(ISBN);
	}


}

//Searches the file for books with their Title 
//Could not really figure out how to make this work
void searchBookDataByTitle(bookType books[], int bookCount, string title, int & loc)
{
	loc = -1;
	ifstream infile;
	infile.open("book.dat", ios::in);
	infile >> bookCount;
	infile.ignore();

	for (int i = 0; i < bookCount; i++)
	{

		getline(infile, title);
		books[i].setTitle(title);
		infile.ignore();

		/*for (int j = 0; j < title; j++)
		{

			//getline(infile, str);
			//books[j].setTitle(str, j);
		}*/
	}



}

//Updates the project  
//Could not really figure out how to make this work
void updateCopiesInStock(bookType books[], int bookCount)
{

}