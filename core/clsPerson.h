#pragma once

#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Birth;
    string _Email;
    string _Phone;

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Property Set (Setter)
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    // Property Get (Getter)
    string GetFirstName()
    {
        return _FirstName;
    }

    // Property Set (Setter)
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    // Property Get (Getter)
    string GetLastName()
    {
        return _LastName;
    }

    // Property Set (Setter)
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    // Property Get (Getter)
    string GetEmail()
    {
        return _Email;
    }

    // Property Set (Setter)
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    // Property Get (Getter)
    string GetPhone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\n==========  Info  ===========:";
        cout << "\n=============================";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n=============================\n";
    }
};
