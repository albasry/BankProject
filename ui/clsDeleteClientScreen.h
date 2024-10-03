#pragma once

#include <iostream>
#include "clsScreen.h"
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\lib\clsBankClient.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n==========================";
		cout << "\nFirstName   : " << Client.GetFirstName();
		cout << "\nLastName    : " << Client.GetLastName();
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.GetEmail();
		cout << "\nPhone       : " << Client.GetPhone();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.GetPinCode();
		cout << "\nBalance     : " << Client.GetAccountBalance();
		cout << "\n==========================\n";
	}

public:
	static void ShowDeleteClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return; // this will exit the function and it will not continue
        }

		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found!" << endl;
			cout << "choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this client? [ y/n ]: ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully :)\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}
	}

};

