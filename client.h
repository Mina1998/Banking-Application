
#pragma once
#include "client.h"
#include "BankAcc.h"
#include"BankApp.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>
#include <cstdlib>

class BankAcc;
class BankApp;

class client 
{
	string name;
	string address;
	string phoneNumber;


	BankAcc *BankAccount;
	BankApp *myBankingApplication;

public:
	client();
	client(string name2, string address2, string phoneNumber2);
	//void setName(string name1);
	//void setAddress(string address1);
	//void setPhoneNumber(string phoneNumber1);

	string getName();
	string getAddress();
	string getphoneNumber();
	void setBankAccount(BankAcc *ba);
	BankAcc* getBankAccount();
	~client();

};
	


