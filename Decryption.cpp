#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include "Decryption.h"

void Decryption::textDecrypt()
{
	if (encrypted.size() != 0)
	{
		encrypted.clear();
	}
	inverseMatrix();
	getInput();
	int sizeOfString = input.size();
	while (sizeOfString % 15 != 0)
	{
		input += " ";
		sizeOfString = input.size();
	}
	int timesToRun = sizeOfString / 15;
	for (int i = 0; i < timesToRun; i++)
	{
		if (i == 0)
		{
			tempHolder = input.substr(0, 15);
		}
		else
		{
			tempHolder = input.substr(i * 15, 15);
		}
		stringToMatrix();
		vectorMultiplication();
		matrixTransformation();
	}
	displayOutput();

}
void Decryption::vectorMultiplication()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
		{
			multipliedMatrix[i][j] = 0;
		}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				multipliedMatrix[i][j] += invertedMatrix[i][k] * (originMatrix[k][j] - 32);
			}
		}
	}

}
/*This function takes in a string and turns it into the correct 3x5 matrix
  It will only be sent 15 char strings. A note, it does not input data
  horizontally, it is inserted vertically into the vector. This is intended*/
void Decryption::stringToMatrix()
{
	vector<int> testerVect;
	int countVec = 0;
	for (int i = 0; i < 15; i++)
	{
		int charToAdd = static_cast<int>(tempHolder[i]);
		testerVect.push_back(charToAdd);
	}
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			originMatrix[i][j] = testerVect[countVec];
			countVec++;
		}
	}
}
/*This takes the matrix that has been encrypted/decrypted and sends the output into a vector
  That vector would be the encrypted data, or the decrypted data if sent in through the other
  class*/
void Decryption::matrixTransformation()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (multipliedMatrix[i][j] % 95 >= 0)
			{
				multipliedMatrix[i][j] = (multipliedMatrix[i][j] % 95) + 32;
				encrypted.push_back(multipliedMatrix[i][j]);
			}
			else
			{
				multipliedMatrix[i][j] = (multipliedMatrix[i][j] % 95) + 127;
				encrypted.push_back(multipliedMatrix[i][j]);
			}
		}
	}
}
//Gets the user input
void Decryption::getInput()
{
	cout << "Enter Input: ";
	cin.ignore();
	getline(cin, input);
}
//Displays the output
void Decryption::displayOutput()
{
	int inputLength = encrypted.size();
	for (int i = 0; i < inputLength; i++)
	{
		cout << static_cast<char>(encrypted[i]);
	}
	cout << endl;
}
//Allows the matrix to be set from the key settings
void Decryption::setMatrix(int param, int i, int j)
{
	matrixToMultiply[j][i] = param;
}
//Used for testting to make sure the matrices are correct
void Decryption::seeMatrix()
{
	cout << endl << "Output Matrix: " << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << " " << multipliedMatrix[i][j];
			if (j == 5 - 1)
			{
				cout << endl;
			}
		}
	}
}
void Decryption::inverseMatrix()
{
	// Calculate the determinant of the matrix
	int a = matrixToMultiply[0][0], b = matrixToMultiply[0][1], c = matrixToMultiply[0][2],
		d = matrixToMultiply[1][0], e = matrixToMultiply[1][1], f = matrixToMultiply[1][2],
		g = matrixToMultiply[2][0], h = matrixToMultiply[2][1], i = matrixToMultiply[2][2];
	int determinant = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

	// Calculate the inverse of the matrix
	invertedMatrix[0][0] = (matrixToMultiply[1][1] * matrixToMultiply[2][2] - matrixToMultiply[2][1] * matrixToMultiply[1][2]) / determinant;
	invertedMatrix[0][1] = (matrixToMultiply[0][2] * matrixToMultiply[2][1] - matrixToMultiply[0][1] * matrixToMultiply[2][2]) / determinant;
	invertedMatrix[0][2] = (matrixToMultiply[0][1] * matrixToMultiply[1][2] - matrixToMultiply[0][2] * matrixToMultiply[1][1]) / determinant;
	invertedMatrix[1][0] = (matrixToMultiply[1][2] * matrixToMultiply[2][0] - matrixToMultiply[1][0] * matrixToMultiply[2][2]) / determinant;
	invertedMatrix[1][1] = (matrixToMultiply[0][0] * matrixToMultiply[2][2] - matrixToMultiply[0][2] * matrixToMultiply[2][0]) / determinant;
	invertedMatrix[1][2] = (matrixToMultiply[1][0] * matrixToMultiply[0][2] - matrixToMultiply[0][0] * matrixToMultiply[1][2]) / determinant;
	invertedMatrix[2][0] = (matrixToMultiply[1][0] * matrixToMultiply[2][1] - matrixToMultiply[2][0] * matrixToMultiply[1][1]) / determinant;
	invertedMatrix[2][1] = (matrixToMultiply[2][0] * matrixToMultiply[0][1] - matrixToMultiply[0][0] * matrixToMultiply[2][1]) / determinant;
	invertedMatrix[2][2] = (matrixToMultiply[0][0] * matrixToMultiply[1][1] - matrixToMultiply[1][0] * matrixToMultiply[0][1]) / determinant;
}