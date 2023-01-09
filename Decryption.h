#pragma once
#include "Encryption.h"
class Decryption
{
private:
    int originMatrix[3][5];
    int matrixToMultiply[3][3] = {{ 0,0,0 }, { 0,0,0 }, { 0,0,0 }};
    int invertedMatrix[3][3];
    int multipliedMatrix[3][5];
    vector<int> encrypted;
    string input = "";
    string tempHolder; 
public:
    void textDecrypt();
    void stringToMatrix();
    void matrixTransformation();
    void getInput();
    void vectorMultiplication();
    void displayOutput();
    void setMatrix(int param, int i, int j);
    void seeMatrix();
    void inverseMatrix();
    
};

