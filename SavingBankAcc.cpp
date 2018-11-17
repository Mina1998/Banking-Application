#include "pch.h"
#include "SavingBankAcc.h"
#include "BankAcc.h"
#include "BankApp.h"
#include <string>
#include <iostream>
using namespace std;

SavingBankAcc::SavingBankAcc()
{
	minimumBalance = 1000;
}
void SavingBankAcc::setMinimumBalance(double minimum_balance_)
{
	minimumBalance = minimum_balance_;
}

double SavingBankAcc::getMinimumBalance()
{
	return minimumBalance;
}

void SavingBankAcc::setBalance(double balance_)// override the setBalance function to match the specif functionality
{
	if (balance_ < minimumBalance)
		cout << "ERROR! The balance must be > " << minimumBalance << endl;

	else
		balance = balance_;
}

void SavingBankAcc::withDraw(double amount)// override the withdraw function to match the specif functionality
{
	double balanceAfterWithdraw = balance - amount;
	if (amount > balance || (balanceAfterWithdraw < minimumBalance)) // must keep minimum balance, as long as the account is open
	{
		cout << "ERROR! Not Enough Balance." << endl;
	}
	else {
		cout << "Successful operation." << endl;
		balance -= amount;
	}

}

void SavingBankAcc::deposit(double amount)// override the deposit function to match the specif functionality
{
	if (amount >= 100)
		balance += amount;
	else
		cout << "ERROR! Sorry, the amoumt must be >= 100" << endl;
}
SavingBankAcc::~SavingBankAcc()
{
}
