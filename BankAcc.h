#pragma once
#include "pch.h"
#include "client.h"
#include "BankAcc.h"
#include "BankApp.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <string>

class client;
class BankApp;

class BankAcc 
{
protected:
	string AccountID;
	double balance;
	string AccountType;

	client *myClient;
	BankApp *myBankingApplication;
public:
	BankAcc();

	BankAcc(double balance_);
	void setAccountID(string id);
	void deposit(double amount);
	void withDraw(double amount);
	string getAccountID();
	void setBalance (double balance_);
	double getBalance();
	void setClient(client* c);
	client* getClient();
	void setAccountID(int num);
	void setAccountType(string type);
	string getAccountType();
	double getMinimumBalance();

	~BankAcc();

   
};

