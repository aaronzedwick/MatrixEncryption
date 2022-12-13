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
    int sizeOfString = input.size();
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
        seeMatrix();
    }
    displayOutput();
}
