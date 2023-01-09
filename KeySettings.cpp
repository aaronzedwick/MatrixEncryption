#include "KeySettings.h"
#include "Encryption.h"
#include "Decryption.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include<sstream>

using namespace std;

void KeySettings::keyChange(Encryption& encrypt, Decryption& decrypt)
{
	string userKey;
	int count = 0;
	cout << endl << "Enter 9 numbers (0-99) with spaces between each number. The matrix that is created must have an inverse with all integers.\nGenerating a key will do this" 
		<< " correctly for you so we suggest using that and saving that key for later input: ";
	cin.ignore();
	getline(cin, userKey);
	// Declare a stringstream object to parse the string
	stringstream inputStream(userKey);

	// Declare the vector to store the parsed numbers
	vector<int> numbers;

	// Declare a variable to store each number as it is parsed
	int n;

	// Parse the numbers from the string and store them in the vector
	while (inputStream >> n) {
		numbers.push_back(n);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//int digit = static_cast<int>(numbers[count]) - 48;
			//key[j][i] = digit;
			int digit = numbers[count];
			key[i][j] = digit;
			encrypt.setMatrix(digit, j, i);
			decrypt.setMatrix(digit, j, i);
			count++;
		}
	}
}

int KeySettings::keyGet(Encryption& encrypt)
{
	return key[0][0];
}

void KeySettings::keyDisplay(Encryption& encrypt, Decryption& decrypt)
{
	int selection = 0;
	do
	{
		cout << "\nYour current key in use: \n";
		for (int i = 0; i < 3; i++)
		{
			cout << " ";
			for (int j = 0; j < 3; j++)
			{
				cout << key[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "1. Generate key to use\n2. Change key\n3. Return\n"
			<< "\nEnter Selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1: generateKey(encrypt, decrypt);
			break;
		case 2: keyChange(encrypt, decrypt);
			break;
		default: selection = 3;
			break;
		}
	} while (selection != 3);
	cout << endl;
}

void KeySettings::generateKey(Encryption& encrypt, Decryption& decrypt)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			key[i][j] = 0;
		}
	}
	srand(time(0));
	int matrix1[3][3] = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };
	int matrix2[3][3] = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };
	matrix1[0][0] = 1;
	matrix1[1][1] = 1;
	matrix1[2][2] = 1;
	matrix1[1][0] = rand() % 9;
	matrix1[2][0] = rand() % 9;
	matrix1[2][1] = rand() % 9;
	matrix2[0][0] = 1;
	matrix2[1][1] = 1;
	matrix2[2][2] = 1;
	matrix2[0][1] = rand() % 9;
	matrix2[0][2] = rand() % 9;
	matrix2[1][2] = rand() % 9;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				key[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			encrypt.setMatrix(key[j][i], i, j);
			decrypt.setMatrix(key[j][i], i, j);
		}
	}
}
