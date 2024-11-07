#pragma once

#include <iostream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\ui\clsScreen.h"
#include "C:\Users\Public\BankProject\lib\clsInputValidate.h"
#include "C:\Users\Public\BankProject\core\clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency, string Message)
	{
		cout << "\n" << Message << "\n";
		cout << "=====================================\n";
		cout << "\nCountry    : " << Currency.GetCountry();
		cout << "\nCode       : " << Currency.GetCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GetRate();
		cout << "\n=====================================\n";
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrency(Currency1, "Convert From");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.GetCurrencyCode();
		cout << " = " << AmountInUSD << " USD.\n";

		if (Currency2.GetCurrencyCode() == "USD")
			return;

		cout << "\nConverting from USD to\n";
		_PrintCurrency(Currency2, "Convert To");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.GetCurrencyCode();
		cout << " = " << AmountInCurrency2 << " " << Currency2.GetCurrencyCode();
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found!";
			cout << "\nChoose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static float _GetAmount(string Message)
	{
		cout << Message;
		float Amount = clsInputValidate::ReadDblNumber();
		return Amount;
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char OtherConvert = 'y';

		while (OtherConvert == 'y' || OtherConvert == 'Y')
		{
			_DrawScreenHeader("\t  Currency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nEnter Currency Code To Convert From: ");
			clsCurrency Currency2 = _GetCurrency("\nEnter Currency Code To Convert To : ");

			float Amount = _GetAmount("\nEnter Amount to Exchange: ");

			_PrintCalculationsResults(Amount, Currency1, Currency2);

			cout << "\nDo you want preform another calculations? [y/n]: ";
			cin >> OtherConvert;
		}
	}
};

