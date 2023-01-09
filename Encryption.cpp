#include <vector>
#include <iostream>
#include <sstream>
#include "Encryption.h"

using namespace std;
/*Gets the user input that is meant to be encrypted*/
void Encryption::getInput()
{
    cout << "Enter Input: ";
    cin.ignore();
    getline(cin, input);
}
/*This functions put everything together and runs all the encryption methods*/
void Encryption::textEncryption()
{
    bool allZero = true;
    if (encrypted.size() != 0)
    {
        encrypted.clear();
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrixToMultiply[i][j] != 0)
            {
                allZero = false;
            }
        }
    }
    if (allZero)
    {
        cout << "\nPlease Enter a valid key\n";
        return;
    }
    getInput();
    int sizeOfString = input.size();
    while (sizeOfString % 15 != 0) //The string MUST be 15 chars for a 3x5 matrix, so this adds spaces if it is not
    {
        input += " ";
        sizeOfString = input.size();
    }
    int timesToRun = sizeOfString / 15; // Gets the number of matrices that will be made
    for (int i = 0; i < timesToRun; i++)
    {
        if (i == 0)
        {
            tempHolder = input.substr(0, 15); // this is the first time it runs, it will get the first 15 chars
        }
        else
        {
            tempHolder = input.substr(i*15, 15); // after the first time it gets the following 15 chars each time it runs
        }
        /*Encryption Functions*/
        stringToMatrix();
        vectorMultiplication();
        matrixTransformation();
    }
    /*Displays output*/
    displayOutput();
    
}
/*This function takes in a string and turns it into the correct 3x5 matrix
  It will only be sent 15 char strings. A note, it does not input data 
  horizontally, it is inserted vertically into the vector. This is intended*/
void Encryption::stringToMatrix() 
{
    vector<int> testerVect;
    int countVec = 0;
    for (int i = 0; i < 15; i++)
    {
        int charToAdd = static_cast<int>(tempHolder[i]);
        testerVect.push_back(charToAdd - 32);
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
void Encryption::seeMatrix()
{
    cout << endl << "Output Matrix: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << " " << matrixToMultiply[i][j];
            if (j == 3 - 1)
            {
                cout << endl;
            }
        }
    }
}
/*This takes the matrix that has been encrypted/decrypted and sends the output into a vector
  That vector would be the encrypted data, or the decrypted data if sent in through the other 
  class*/
void Encryption::matrixTransformation()
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            mutipliedMatrix[i][j] = (mutipliedMatrix[i][j] % 95) + 32;
            encrypted.push_back(mutipliedMatrix[i][j]);
        }
    }
}
/*This multiples the vectors together, to transform the text into something based off of the
3x3 matrix which would be your key. This is the main encryption method.*/
void Encryption::vectorMultiplication()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 5; ++j)
        {
            mutipliedMatrix[i][j] = 0;
        }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                mutipliedMatrix[i][j] += matrixToMultiply[i][k] * (originMatrix[k][j]);
            }
        }
    }
}
/*Loops through the vector that holds the data stored by a previous function*/
void Encryption::displayOutput()
{
    int inputLength = encrypted.size();
    cout << endl << "Your encrypted string:\n";
    for (int i = 0; i < inputLength; i++)
    {
        cout << static_cast<char>(encrypted[i]);
    }
    cout << endl;
}

void Encryption::setMatrix(int param, int i, int j)
{
    matrixToMultiply[j][i] = param;
}
