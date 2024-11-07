#pragma once

#include <iostream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\core\clsCurrency.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "=====================================\n";
        cout << "\nCountry    : " << Currency.GetCountry();
        cout << "\nCode       : " << Currency.GetCurrencyCode();
        cout << "\nName       : " << Currency.GetCurrencyName();
        cout << "\nRate(1$) = : " << Currency.GetRate();
        cout << "\n=====================================\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << setw(37) << left << "" << "Find By: [1] Code or [2] Country: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "\t\t\t\t     Find By: [1] Code or [2] Country: ");

        if (Choice == 1)
        {
            string CurrencyCode;
            cout << "\n\t\t\t\t     Please Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\n\t\t\t\t     Please Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
    }
};

