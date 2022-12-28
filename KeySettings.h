#pragma once
#include <vector>

using namespace std;
class KeySettings
{
private:
	int key[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
public:
	void keySet();
	int keyGet();
	void keyDisplay();
	void generateKey();
};

