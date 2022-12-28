#include <iostream>
#include <cmath>
#include <vector>
#include "Encryption.h"
#include "Decryption.h"
#include "KeySettings.h"

using namespace std;
int main()
{
    int menuChoice = 0;
    while (menuChoice != 4)
    {
        Encryption encrypt;
        Decryption decrypt;
        KeySettings key;
        cout << "1. Encrypt\n2. Decrypt\n3. Edit Key Settings\n4. Exit\n\nEnter Selection: ";
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 1: encrypt.textEncryption();
                break;
            case 2: decrypt.textDecrypt();
                break;
            case 3: key.keyDisplay();
                break;
            default: menuChoice = 4;
                break;
        }
    }
    return 0;
}
