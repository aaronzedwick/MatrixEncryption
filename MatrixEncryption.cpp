#include <iostream>
#include <cmath>
#include <vector>
#include "Encryption.h"
#include "Decryption.h"

using namespace std;
int main()
{
    int menuChoice = 0;
    while (menuChoice != 3)
    {
        Encryption encrypt;
        Decryption decrypt;
        cout << "\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter Choice: ";
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 1: encrypt.textEncryption();
                break;
            case 2: decrypt.textDecrypt();
                break;
            default: menuChoice = 3;
                break;
        }
    }
    return 0;
}
