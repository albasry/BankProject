#pragma once

#include <iostream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\core\clsBankClient.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &Client)
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
        cout << "\nPincode     : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n==========================\n";
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return; // this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found! " << endl;
            cout << "choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client? [y/n]: ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n==========================\n";

            _ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};
