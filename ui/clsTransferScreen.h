#pragma once

#include <iostream>
#include "clsScreen.h"
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\lib\clsBankClient.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber(string FromAndTo)
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber to Transfer " << FromAndTo << ": ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist!\n";
			cout << "Please enter AccountNumber to Transfer " << FromAndTo << ": ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient sourceClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > sourceClient.GetAccountBalance())
		{
			cout << "\nAmout Exceeds the Availeble Balance!\n";
			cout << "Enter Transfer amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n==========================";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.GetAccountBalance();
		cout << "\n==========================\n";
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this transaction? [y/n]: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.GetUserName()))
				cout << "\nTransfer Done Successfully :)\n";
			else
				cout << "\nOperation was cancelled!\n";
		}
		else
		{
			cout << "\nOperation was cancelled!\n";
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

