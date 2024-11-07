#pragma once

#include <iostream>
#include <iomanip>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsMainScreen.h"
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\core\Global.h"
#include "C:\Users\Public\BankProject\core\clsUser.h"

class clsLoginScreen : protected clsScreen
{
private:
    static  bool _Login()
    {
        bool LoginFaild = false;
        short Counter = 3;

        string Username = "";
        string Password = "";

        do
        {
            if (LoginFaild)
            {
                Counter--;

                if (Counter == 0)
                {
                    cout << "\n\t\t\t\t\tYou are locked!!\n";
                    return false;
                }

                cout << "\n\t\t\t\t\tInvlaid Username/Password!\n\n";
                cout << "\t\t\t\t\tYou have " << Counter << " trials to login.\n\n";
            }

            cout << "\t\t\t\t\tEnter Username: ";
            cin >> Username;

            cout << "\t\t\t\t\tEnter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};

