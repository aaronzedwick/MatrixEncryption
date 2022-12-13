#pragma once
#include <vector>
#include <iostream> 
using namespace std;

class Encryption
{
private:
    int originMatrix[3][5];
    int matrixToMultiply[3][3] = { {1, 5, 3}, {2, 11, 8}, {4, 24, 21} };
    int mutipliedMatrix[3][5];
    vector<int> encrypted;
    string input = "";
    string tempHolder;
public:
    void getInput();
    void textEncryption();
    void stringToMatrix();
    void seeMatrix();
    void matrixTransformation();
    void vectorMultiplication();
    void displayOutput();
};

