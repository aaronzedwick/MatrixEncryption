#pragma once
#include <vector>
#include <iostream> 
using namespace std;

class Encryption
{
private:
    int originMatrix[3][5];
    int matrixToMultiply[3][3] = { { 0,0,0 }, { 0,0,0 }, { 0,0,0 } };
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
    void setMatrix(int param, int i, int j);
};

