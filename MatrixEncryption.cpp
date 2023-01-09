#include <iostream>
#include <cmath>
#include <vector>
#include "Encryption.h"
#include "Decryption.h"
#include "KeySettings.h"
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
    int menuChoice = 0;
    Encryption encrypt;
    Decryption decrypt;
    KeySettings key;
    while (menuChoice != 4)
    {
        cout << "\nMake sure to edit key settings and generate a key to use, otherwise you won't be using any key\n1. Encrypt\n2. Decrypt\n3. Edit Key Settings\n4. Exit\n\nEnter Selection: ";
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 1: encrypt.textEncryption();
                break;
            case 2: decrypt.textDecrypt();
                break;
            case 3: key.keyDisplay(encrypt, decrypt);
                break;
            default: menuChoice = 4;
                break;
        }
    }
    return 0;
}
