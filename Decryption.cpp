#include <vector>
#include <iostream>
#include <sstream>
#include "Decryption.h"

void Decryption::textDecrypt()
{
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
        //seeMatrix();
    }
    displayOutput();
}
void Decryption::getInput()
{
    cout << "Enter Input: ";
    cin.ignore();
    getline(cin, input);
}
/*This functions put everything together and runs all the encryption methods*/
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
/*Displays the matrix in an easy to see way*/
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
/*This takes the matrix that has been encrypted/decrypted and sends the output into a vector
  That vector would be the encrypted data, or the decrypted data if sent in through the other
  class*/
void Decryption::matrixTransformation()
{
    cout << "'" << multipliedMatrix[1][2] << "'" << endl;
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
    cout << endl << "Output Matrix Test3: " << endl;
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
/*This multiples the vectors together, to transform the text into something based off of the
3x3 matrix which would be your key. This is the main encryption method.*/
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
                //originMatrix[k][j] = originMatrix[k][j] - 32;
                multipliedMatrix[i][j] += matrixToMultiply[i][k] * (originMatrix[k][j] - 32);
            }
        }
    }
    cout << endl << "Multiplied Matrix: " << endl;
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
/*Loops through the vector that holds the data stored by a previous function*/
void Decryption::displayOutput()
{
    int inputLength = encrypted.size();
    for (int i = 0; i < inputLength; i++)
    {
        cout << static_cast<char>(encrypted[i]);
    }
    cout << endl;
}