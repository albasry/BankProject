#pragma once

#include <iostream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\core\clsUser.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n==========================";
		cout << "\nFirstName   : " << User.GetFirstName();
		cout << "\nLastName    : " << User.GetLastName();
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.GetEmail();
		cout << "\nPhone       : " << User.GetPhone();
		cout << "\nUser Name   : " << User.GetUserName();
		cout << "\nPassword    : " << User.GetPassword();
		cout << "\nPermissions : " << User.GetPermissions();
		cout << "\n==========================\n";
	}

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found!" << endl;
            cout << "Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User? [y/n]: ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted!\n";
            }
        }
    }

};

