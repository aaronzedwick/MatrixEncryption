#include "KeySettings.h"
#include "Encryption.h"
#include "Decryption.h"
#include <vector>
#include<iostream>

using namespace std;

void KeySettings::keySet()
{

}

int KeySettings::keyGet()
{
	return key[0][0];
}

void KeySettings::keyDisplay()
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
		cout << "1. Generate key to use\n2. Change key (make sure the key follows the rules or it will be denied)\n3. Return\n"
			<< "\nEnter Selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1: generateKey();
			break;
		case 2: keySet();
			break;
		default: selection = 3;
			break;
		}
	} while (selection != 3);
	cout << endl;
}

void KeySettings::generateKey()
{
	Encryption keySetter;
	srand(time(0));
	int matrix1[3][3];
	int matrix2[3][3];
	int matrix3[3][3];
	matrix1[0][0] = 1;
	matrix1[1][1] = 1;
	matrix1[2][2] = 1;
	matrix1[0][1] = 0;
	matrix1[0][2] = 0;
	matrix1[1][2] = 0;
	matrix1[1][0] = rand() % 9;
	matrix1[2][0] = rand() % 9;
	matrix1[2][1] = rand() % 9;
	matrix2[0][0] = 1;
	matrix2[1][1] = 1;
	matrix2[2][2] = 1;
	matrix2[0][1] = rand() % 9;
	matrix2[0][2] = rand() % 9;
	matrix2[1][2] = rand() % 9;
	matrix2[1][0] = 0;
	matrix2[2][0] = 0;
	matrix2[2][1] = 0;
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
			keySetter.setMatrix(key[j][i], i, j);
		}
	}
}
