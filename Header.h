#pragma once
// Name: Saori Kojima
// Program Description: Final Project: header file
// Date: 11/17/2022

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

/* -------------------
	Generic Functions
   ------------------- */

// Error Check ... check if the input file exists
void fileCheck(ifstream& inFile, string text)
{
	if (!inFile.is_open())
	{
		cout << text << " Not Found" << endl;
		exit(1);
	}
}

// Remove HTML tag
void tagRemove(string& text)
{
	for (int a = 0; a < text.length(); a++)
	{
		if (text[a] == '<')
		{
			// Search for the closing tag
			for (int b = a; b < text.length(); b++)
			{
				if (text[b] == '>')
				{
					// erase the letters between < and >
					text.erase(a, (b - a) + 1);

					// in case contiunous tags
					a--;
					break;
				}
			}
		}
	}
}

// Sort
void bblSort(vector<string>& data1, vector<int>& data2, vector<double>& data3)
{
	// Temporary Strage for switching value
	string tempS;
	int tempI;
	double tempD;

	// Sort by data1
	for (int a = 0; a < data1.size(); a++)
	{
		for (int b = 0; b < data1.size() - 1; b++)
		{
			if (data1[b] > data1[b + 1])
			{
				// data1
				tempS = data1[b];
				data1[b] = data1[b + 1];
				data1[b + 1] = tempS;

				// data2
				tempI = data2[b];
				data2[b] = data2[b + 1];
				data2[b + 1] = tempI;

				// data3
				tempD = data3[b];
				data3[b] = data3[b + 1];
				data3[b + 1] = tempD;
			}
		}
	}
}

void bblSort(vector<int>& data1, vector<string>& data2, vector<double>& data3)
{
	// Temporary Strage for switching value
	string tempS;
	int tempI;
	double tempD;

	// Sort by data1
	for (int a = 0; a < data1.size(); a++)
	{
		for (int b = 0; b < data1.size() - 1; b++)
		{
			if (data1[b] > data1[b + 1])
			{
				// data1
				tempI = data1[b];
				data1[b] = data1[b + 1];
				data1[b + 1] = tempI;

				// data2
				tempS = data2[b];
				data2[b] = data2[b + 1];
				data2[b + 1] = tempS;

				// data3
				tempD = data3[b];
				data3[b] = data3[b + 1];
				data3[b + 1] = tempD;
			}
		}
	}
}

void bblSort(vector<double>& data1, vector<string>& data2, vector<int>& data3)
{
	// Temporary Strage for switching value
	string tempS;
	int tempI;
	double tempD;

	// Sort by data1
	for (int a = 0; a < data1.size(); a++)
	{
		for (int b = 0; b < data1.size() - 1; b++)
		{
			if (data1[b] > data1[b + 1])
			{
				// data1
				tempD = data1[b];
				data1[b] = data1[b + 1];
				data1[b + 1] = tempD;

				// data2
				tempS = data2[b];
				data2[b] = data2[b + 1];
				data2[b + 1] = tempS;

				// data3
				tempI = data3[b];
				data3[b] = data3[b + 1];
				data3[b + 1] = tempI;
			}
		}
	}
}

// Find largest/smallest value
int findMax(vector<double>& compData)
{
	int position = 0;

	for (int a = 0; a < compData.size() - 1; a++)
	{
		if (compData[a] < compData[a + 1])
		{
			position = a + 1;
		}
	}

	return position;
}

int findMin(vector<double>& compData)
{
	int position = 0;

	for (int a = 0; a < compData.size() - 1; a++)
	{
		if (compData[a] > compData[a + 1])
		{
			position = a + 1;
		}
	}

	return position;
}


/* ------------
	Base Class
   ------------ */

class person {
public:
	// Get Data
	void getPersonData()
	{
		// temp
		string tfName, tlName, tMovie;

		// Open input file
		inFile.open("person.txt");
		fileCheck(inFile, "person.txt");

		while (!inFile.eof())
		{
			// Input Data to temp
			inFile >> tfName >> tlName;
			inFile.ignore();
			getline(inFile, tMovie);

			// Remove HTML tag in movie's name
			tagRemove(tMovie);

			// Store in vectors
			fName.push_back(tfName);
			lName.push_back(tlName);
			favMovie.push_back(tMovie);

		}

		// Close inout file
		inFile.close();
	}

private:

	ifstream inFile;

protected:

	vector<string> fName, lName, favMovie;

};
