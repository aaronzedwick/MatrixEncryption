#pragma once
#include <vector>
#include "Encryption.h"
#include "Decryption.h"

using namespace std;
class KeySettings
{
private:
	int key[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
public:
	void keyChange(Encryption& encrypt, Decryption& decrypt);
	int keyGet(Encryption& encrypt);
	void keyDisplay(Encryption& encrypt, Decryption& decrypt);
	void generateKey(Encryption& encrypt, Decryption& decrypt);
};

