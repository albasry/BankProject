#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\core\Global.h"
#include "clients\clsClientListScreen.h"
#include "clients\clsAddNewClientScreen.h"
#include "clients\clsDeleteClientScreen.h"
#include "clients\clsUpdateClientScreen.h"
#include "clients\clsFindClientScreen.h"
#include "clients\clsTransactionsScreen.h"
#include "users\clsManageUsersScreen.h"
#include "users\clsLoginScreen.h"
#include "users\clsLoginRegisterScreen.h"
#include "currencies\clsCurrencyExchangeMainScreen.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions 
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eCurrencyExchange = 9,
        eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between [1 to 10]: ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        // cout << setw(37) << left << "" << "\n\tClient List Screen Will be here...";
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << setw(37) << left << "" << "\n\tAdd New Client Screen Will be here...";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << setw(37) << left << "" << "\n\tDelete Client Screen Will be here...";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << setw(37) << left << "" << "\n\tUpdate Client Screen Will be here...";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        // cout << setw(37) << left << "" << "\n\tFind Client Screen Will be here...";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        // cout << setw(37) << left << "" << "\n\tTransactions Menue Will be here...";
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        // cout << setw(37) << left << "" << "\n\tUsers Menue Will be here...";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        // then it will go back to main function.
        cout << setw(37) << left << "" << "\n\tLoguot...";
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;

        case enMainMenueOptions::eExit:
            system("cls");
            // _ShowEndScreen();
            _Logout();

            break;
        }
    }


public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "\t [1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t [2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t [3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t [4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t [5] Find Client.\n";
        cout << setw(37) << left << "" << "\t [6] Transactions.\n";
        cout << setw(37) << left << "" << "\t [7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t [8] Login Register.\n";
        cout << setw(37) << left << "" << "\t [9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};

