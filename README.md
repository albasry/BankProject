# Bank project
> **Console App,** Run code in a terminal.

Clean code was implemented:
- Readable
- Testable
- Maintainable
- Extensible

OOP principles was implemented:
- Abstraction
- Inheritance
- Encapsulation
- Polymorphism

Upon running the project, a login screen will appear. Use one of the provided usernames and passwords to log in.
- Username: User1, password: 1111
- Username: User2, password: 2222
---
![Main Screen](https://github.com/albasry/BankProject/blob/main/img/MainScreen.png 'Main Screen')
---
## What can this project do?
1. Show Clients List
2. Add New Clients
3. Delete Clients
4. Update Client Informations
5. Find Clients
6. Transactions
   1. Deposit
   2. Withdraw
   3. Total Balances
   4. Transfer
   5. Transfer Log
   6. Back to Main Menue
7. Manage Users
   1. Show Users List
   2. Add New Users
   3. Delete Users
   4. Update Users
   5. Find Users
   6. Back to Main Menue
8. Login Register
9.  Logout

# Classes

## Person class
``clsPerson``
What this class contains.

Contains these members below.
- SetFirstName
- GetFirstName
- SetLastName
- GetLastName
- SetEmail
- GetEmail
- SetPhone
- GetPhone
- FullName

Contains these methods below.
* **Print**

## Banck client class
``clsBankClient`` 
What this class contains.

Contains these members below.
- AccountNumber
- SetPinCode
- GetPinCode
- SetAccountBalance
- GetAccountBalance

Contains these methods below.
* **Find**
* **IsEmpty**
* **Print**
* **IsClientExist**
* **Save**
* **Delete**
* **GetAddNewClientObject**
* **GetClientsList**
* **GetTotalBalances**
* **Deposit**
* **Withdraw**
* **Transfer**
* **GetTransfersLogList**

## User class
``clsUser`` 
What this class contains.

Contains these members below.
- GetUserName
- SetUserName
- SetPassword
- GetPassword
- SetPermissions
- GetPermissions

Contains these methods below.
* **Find**
* **IsEmpty**
* **MarkedForDeleted**
* **IsUserExist**
* **Save**
* **Delete**
* **GetAddNewUserObject**
* **GetUsersList**
* **CheckAccessPermission**
* **RegisterLogIn**
* **GetLoginRegisterList**

---
# Local libraries

## String library
``clsString``
What this library contains.

Contains these methods below.
* **Length**
* **CountWords**
* **UpperFirstLetterOfEachWord**
* **LowerFirstLetterOfEachWord**
* **UpperAllString**
* **LowerAllString**
* **InvertLetterCase**
* **InvertAllLettersCase**
* **CountLetters**
* **CountCapitalLetters**
* **CountSmallLetters**
* **CountSpecificLetter**
* **IsVowel**
* **CountVowels**
* **Split**
* **TrimLeft**
* **TrimRight**
* **Trim**
* **JoinString**
* **ReverseWordsInString**
* **ReplaceWord**
* **RemovePunctuations**


## Input validate library
``clsInputValidate``
What this library contains.

Contains these methods below.
* **IsNumberBetween**
* **IsDateBetween**
* **IsValideDate**
* **ReadIntNumber**
* **ReadIntNumberBetween**
* **ReadFloatNumber**
* **ReadFloatNumberBetween**
* **ReadDblNumber**
* **ReadDblNumberBetween**
* **ReadString**

## Utilities library
``clsUtil``
What this library contains.

Contains these methods below.
* **RandomNumber**
* **GetRandomCharacter**
* **GenerateWord**
* **GenerateKey**
* **GenerateKeys**
* **FillArrayWithRandomNumbers**
* **FillArrayWithRandomWords**
* **FillArrayWithRandomKeys**
* **Swap**
* **ShuffleArray**
* **Tabs**
* **NumberToText**
* **EncryptWord**
* **DecryptWord**

## Date library
``clsDate``
What this library contains.

Contains these members below.
- SetDay
- GetDay
- SetMonth
- GetMonth
- SetYear
- GetYear

Contains these methods below.
* **Print**
* **GetSystemDate**
* **IsValidDate**
* **IsValid**
* **DateToString**
* **isLeapYear**
* **NumberOfDaysInAYear**
* **NumberOfHoursInAYear**
* **NumberOfMinutesInAYear**
* **NumberOfSecondsInAYear**
* **NumberOfDaysInAMonth**
* **NumberOfHoursInAMonth**
* **NumberOfMinutesInAMonth**
* **NumberOfSecondsInAMonth**
* **DayOfWeekOrder**
* **DayShortName**
* **MonthShortName**
* **PrintMonthCalendar**
* **PrintYearCalendar**
* **DaysFromTheBeginingOfTheYear**
* **GetDateFromDayOrderInYear**
* **AddDays**
* **IsDate1BeforeDate2**
* **IsDate1EqualDate2**
* **IsDate1AfterDate2**
* **IsLastDayInMonth**
* **IsLastMonthInYear**
* **AddOneDay**
* **SwapDates**
* **GetDifferenceInDays**
* **CalculateMyAgeInDays**
* **IncreaseDateByOneWeek**
* **IncreaseDateByXWeeks**
* **IncreaseDateByOneMonth**
* **IncreaseDateByXDays**
* **IncreaseDateByXMonths**
* **IncreaseDateByOneYear**
* **IncreaseDateByXYears**
* **IncreaseDateByOneDecade**
* **IncreaseDateByXDecades**
* **IncreaseDateByOneCentury**
* **IncreaseDateByOneMillennium**
* **DecreaseDateByOneDay**
* **DecreaseDateByXDays**
* **DecreaseDateByOneWeek**
* **DecreaseDateByXWeeks**
* **DecreaseDateByOneMonth**
* **DecreaseDateByXMonths**
* **DecreaseDateByOneYear**
* **DecreaseDateByXYears**
* **DecreaseDateByOneDecade**
* **DecreaseDateByXDecades**
* **DecreaseDateByOneCentury**
* **DecreaseDateByOneMillennium**
* **IsEndOfWeek**
* **IsWeekEnd**
* **IsBusinessDay**
* **DaysUntilTheEndOfWeek**
* **DaysUntilTheEndOfMonth**
* **DaysUntilTheEndOfYear**
* **CalculateBusinessDays**
* **CalculateVacationDays**
* **CalculateVacationReturnDate**
* **CompareDates**

---
# User Interface

## Screen
``clsScreen``
What this library contains.
> Print a general screen, Where other screens can inherit it.


## Main screen
``clsMainScreen``
What this library contains.

Contains these methods below.
* **ShowMainMenue**

## Client list screen
``clsClientListScreen``
What this library contains.

Contains these methods below.
* **ShowClientsList**

## Add new client screen
``clsAddNewClientScreen``
What this library contains.

Contains these methods below.
* **ShowAddNewClientScreen**

## Delete client screen
``clsDeleteClientScreen``
What this library contains.

Contains these methods below.
* **ShowDeleteClientScreen**

## Update client screen
``clsUpdateClientScreen``
What this library contains.

Contains these methods below.
* **ShowUpdateClientScreen**

## Find Client Screen
``clsFindClientScreen``
What this library contains.

Contains these methods below.
* **ShowFindClientScreen**

## Transactions Screen
``clsTransactionsScreen``
What this library contains.

Contains these methods below.
* **ShowTransactionsMenue**

## Deposit Screen
``clsDepositScreen``
What this library contains.

Contains these methods below.
* **ShowDepositScreen**

## Withdraw Screen
``clsWithdrawScreen``
What this library contains.

Contains these methods below.
* **ShowWithdrawScreen**

## Total Balances Screen
``clsTotalBalancesScreen``
What this library contains.

Contains these methods below.
* **ShowTotalBalances**

## Transfer Screen
``clsTransferScreen``
What this library contains.

Contains these methods below.
* **ShowTransferScreen**

## Manage Users Screen
``clsManageUsersScreen``
What this library contains.

Contains these methods below.
* **ShowManageUsersMenue**

## Add new User screen
``clsAddNewUserScreen``
What this library contains.

Contains these methods below.
* **ShowAddNewUserScreen**

## List Users Screen
``clsListUsersScreen``
What this library contains.

Contains these methods below.
* **ShowUsersList**

## Delete User screen
``clsDeleteUserScreen``
What this library contains.

Contains these methods below.
* **ShowDeleteUserScreen**

## Update User screen
``clsUpdateUserScreen``
What this library contains.

Contains these methods below.
* **ShowUpdateUserScreen**

## Find User Screen
``clsFindUserScreen``
What this library contains.

Contains these methods below.
* **ShowFindUserScreen**

## Login Screen
``clsLoginScreen``
What this library contains.

Contains these methods below.
* **ShowLoginScreen**

## Transfer Log Screen
``clsTransferLogScreen``
What this library contains.

Contains these methods below.
* **ShowTransferLogScreen**

## Login Register Screen
``clsLoginRegisterScreen``
What this library contains.

Contains these methods below.
* **ShowLoginRegisterScreen**

