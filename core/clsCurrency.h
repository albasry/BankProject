#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// Note: Put the correct path to find the file.
#include "C:\Users\Public\BankProject\lib\clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.GetCountry() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.GetRate());

		return stCurrencyRecord;
	}

	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open("db/Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{
		fstream MyFile;
		MyFile.open("db/Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{
		return _LoadCurrencysDataFromFile();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	float GetRate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("db/Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("db/Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		return (Currency2.GetCurrencyCode() == "USD") ? AmountInUSD : (float)(AmountInUSD * Currency2.GetRate());
	}
};

