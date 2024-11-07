#pragma once

#include <iostream>
#include <iomanip>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\core\clsUser.h"
#include "C:\Users\Public\BankProject\core\Global.h"
#include "C:\Users\Public\BankProject\lib\clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\n";
        cout << setw(37) << left << "" << "===========================================";
        cout << "\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\n\t\t\t\t\tUser: " << CurrentUser.GetUserName();
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
	}

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t===========================================";
            cout << "\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t===========================================\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};

