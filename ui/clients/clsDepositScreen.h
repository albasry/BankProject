#pragma once

#include <iostream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\core\clsBankClient.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private:
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nEnter AccountNumber: ";
        cin >> AccountNumber;
        return AccountNumber;
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
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t  Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist!\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount: ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? [y/n]: ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);

            cout << "\nAmount Deposited Successfully :)\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
        }
        else
        {
            cout << "\nOperation was cancelled!\n";
        }
    }
};
