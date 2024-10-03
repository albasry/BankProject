#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\lib\clsBankClient.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
        cout << "\nEnter Firstname      : ";
        Client.SetFirstName(clsInputValidate::ReadString());
        cout << "Enter Lastname       : ";
        Client.SetLastName(clsInputValidate::ReadString());
        cout << "Enter Email          : ";
        Client.SetEmail(clsInputValidate::ReadString());
        cout << "Enter Phone          : ";
        Client.SetPhone(clsInputValidate::ReadString());
        cout << "Enter Pincode        : ";
        Client.SetPinCode(clsInputValidate::ReadString());
        cout << "Enter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
	}

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
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return; // this will exit the function and it will not continue
        }

		_DrawScreenHeader("\t  Add New Client Screen");

		string AccountNumber = "";

		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used!" << endl;
			cout << "Choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}
	}
};

