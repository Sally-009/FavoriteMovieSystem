// Name: Saori Kojima
// Program Description: Final Project
// Date: 11/16/2022 - 11/18/2022

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"header.h"

using namespace std;

//CLASS
class movie : public person{
public:

	// test
	void outputAll()
	{
		for (int i = 0; i < mName.size(); i++)
		{
			cout << "Movie #" << i + 1 << endl;
			cout << "Name: " << mName[i] << endl;
			cout << "Year: " << year[i] << endl;
			cout << "Box Office: $" << boxOffice[i] << " million" << endl;
			findFavoMovie(i);
			cout << endl;
		}
	}

	// Menu
	void menu()
	{
		// Get Data
		getPersonData();
		getMovieInfo();

		// Menu
		int choice;
		bool choiceError = false;

		int i; // for vector position

		do
		{
			// Top Menu
			logo();

			if (choiceError == true)
			{
				cout << "*Input Error*" << endl;
				cout << "Please select again." << endl;
				cout << endl;

				choiceError = false;
			}

			cout << "Choose option: " << endl;
			cout << "1. Sort on the movie name" << endl;
			cout << "2. Sort on the box office gross" << endl;
			cout << "3. Sort on the year the movie was made" << endl;
			cout << "4. Display the highest grossing movie's info" << endl;
			cout << "5. Display the lowest grossing movie's info" << endl;
			cout << "6. Exit" << endl;
			cout << "---------------------------------------------" << endl;
			cout << ">> ";
			cin >> choice;

			logo();

			switch (choice)
			{
			case 1:
				cout << "Sort on the movie name" << endl << endl;
				bblSort(mName, year, boxOffice);
				break;

			case 2:
				cout << "Sort on the box office gross" << endl << endl;
				bblSort(boxOffice, mName, year);
				break;

			case 3:
				cout << "Sort on the year the movie was made" << endl << endl;
				bblSort(year, mName, boxOffice);
				break;

			case 4:
				cout << "the highest grossing movie's info" << endl << endl;
				i = findMax(boxOffice);
				break;

			case 5:
				cout << "the lowest grossing movie's info" << endl << endl;
				i = findMin(boxOffice);
				break;

			case 6:

				break;

			default:
				choiceError = true;
				break;
			}

			if (choice >= 1 && choice <= 3)
			{
				outputAll();
				cout << "---------------------------------------------" << endl;
				system("pause");
			}
			else if (choice == 4 || choice == 5)
			{
				output(i);
				cout << "---------------------------------------------" << endl;
				system("pause");
			}

		} while (choice != 6);

		cout << "Exit Successfully . . . " << endl << endl;

	}

	void logo()
	{
		system("cls");

		cout << "------------------------" << endl;
		cout << "     Favorite Movie     " << endl;
		cout << "------------------------" << endl;
		cout << endl;
	}

	void output(int i)
	{
		cout << "Name: " << mName[i] << endl;
		cout << "Year: " << year[i] << endl;
		cout << "Box Office: $" << boxOffice[i] << " million" << endl;
		findFavoMovie(i);
		cout << endl;
	}

	// input data and remove HTML tag
	void getMovieInfo()
	{
		// temporary values
		string tName;
		int tYear;
		double tBox;

		// open file
		inFile.open("movie.txt");
		fileCheck(inFile, "movie.txt");

		while (!inFile.eof())
		{
			// Store data to temporary values
			getline(inFile, tName);
			inFile >> tYear;
			inFile >> tBox;
			inFile.ignore();

			// Remove HTML tag in movie's name
			tagRemove(tName);

			// Store to vectors
			mName.push_back(tName);
			year.push_back(tYear);
			boxOffice.push_back(tBox);
		}

		// close file
		inFile.close();
	}

	// find movies that match to person's favorite.
	void findFavoMovie(int i)
	{
		for (int a = 0; a < favMovie.size(); a++)
		{
			if (mName[i] == favMovie[a])
			{
				cout << "* This movie is liked by " << fName[a] << "!" << endl;
			}
		}
		
	}

private:

	ifstream inFile;

	vector<string> mName;
	vector<int> year;
	vector<double> boxOffice;
};

//MAIN
int main() {

	movie favo;

	favo.menu();

}