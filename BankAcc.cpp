#include "pch.h"
#include "BankAcc.h"
#include "client.h"
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

BankAcc::BankAcc() {
	balance = 0;
}
BankAcc::BankAcc(double balance_)
{
	balance = balance_;
}
string BankAcc::getAccountID()
{
	return AccountID;
}
void BankAcc::setBalance(double balance_)
{
	balance = balance_;
}
double BankAcc::getBalance()
{
	return balance;
}

void BankAcc::setClient(client* c)
{
	myClient = c;
}
client* BankAcc::getClient()
{
	return myClient;
}

void BankAcc::setAccountID(int num)
{

	char integer_string[5];
	sprintf_s(integer_string, "%d", num);

	char s[10] = "FCI-";
	strcat_s(s, integer_string);
	setAccountID(s);

}
void BankAcc::setAccountID(string id)
{
	AccountID = id;
}
void BankAcc::setAccountType(string type)
{
	AccountType = type;
}

string BankAcc::getAccountType()
{
	return AccountType;
}

double BankAcc::getMinimumBalance()
{
	return 0.0;
}


//*************************** member functions *************************** //
void BankAcc::withDraw(double amount)
{
	if (amount < 0)
		cout << "ERROR! Amount Can't be negative." << endl;
	else if (amount > balance)
		cout << "ERROR! Not Enough balance." << endl;
	else {
		cout << "Successful operation." << endl;
		balance -= amount;
	}

}

void BankAcc::deposit(double amount)
{
	if (amount < 0)
		cout << "ERROR! Amount Can't be negative." << endl;
	else
		balance += amount;
}

BankAcc::~BankAcc()
{
}
