#pragma once
//#include <string>
//#include <vector>
//#include "BankAcc.h"
//#include <string.h>
#include <assert.h>
//#include "SavingBankAcc.h"
//#include "client.h"
#include <string>

using namespace std;
class client;
class BankAcc;
class SavingBankAcc;

class BankApp
{
private:
	client* clients;
	BankAcc* accounts;
	int accountsNum;
	bool findAccountbyID(string accountID, BankAcc &ba);
public:
	BankApp();
	void start();
	bool createNewAccount(string clientName, string clientAddress, string clientPhoneNumber, int accountType, double startingBalance);
	void listClientsAndAccounts();
	void withdrawMoney(string accountID);
	void depositMoney(string accountID);
	~BankApp();
};


