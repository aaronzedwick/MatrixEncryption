#pragma once
#include "Encryption.h"
class Decryption :
    public Encryption // this class is inherited so I can use the preprogrammed matrix functions
{
private:
    //These are the same private variables as in the encryption files, so the functions will work between both classes
    int originMatrix[3][5];
    int matrixToMultiply[3][3] = { {39, -33, 7}, {-10, 9, -2}, {4, -4, 1} }; // this is the inverse of the matrix entered on encryption
    int mutipliedMatrix[3][5];
    vector<int> encrypted;
    string input = "";
    string tempHolder; 
public:
    void textDecrypt();
};

