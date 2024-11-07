#include <iostream>
#include "ui\users\clsLoginScreen.h"
using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			cout << "\t\t\t\t\tTry again later...";
			break;
		}
	}

	system("pause>0");
	return 0;
}

