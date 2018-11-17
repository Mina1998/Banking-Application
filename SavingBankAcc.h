#pragma once
#include "pch.h"
#include "BankAcc.h"
#include "client.h"
#include "BankApp.h"
#include <assert.h>
#include <iostream>
#include <string>
class client;

class SavingBankAcc : public BankAcc
{
	double minimumBalance;
public:
	SavingBankAcc();
	void setMinimumBalance(double minimum_balance_);
	void deposit(double amount);
	double getMinimumBalance();
	void setBalance(double balance_);// override the setBalance function to match the specif functionality
	void withDraw(double amount);
	~SavingBankAcc();



};

