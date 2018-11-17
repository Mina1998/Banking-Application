#include "pch.h"
#include "client.h"
#include <iostream>
#include <string>
#include "BankAcc.h"

using namespace std;

client::client() {
}
client::client(string name2 , string address2 , string phoneNumber2)
{
	name = name2;
	address = address2;
	phoneNumber = phoneNumber2;
}
/*void client::setName(string name1)
{
	name = name1;
}*/
string client::getName()
{
	return name;
}
/*void client::setAddress(string address1)
{
	address = address1;
}*/
string client::getAddress()
{
	return address;
}
/*void client::setPhoneNumber(string phoneNumber1)
{
	phoneNumber = phoneNumber1;
}*/
string client::getphoneNumber()
{
	return phoneNumber;
}

void client::setBankAccount(BankAcc* ba)
{
	BankAccount = ba;
}

BankAcc* client::getBankAccount()
{
	return BankAccount;
}


client::~client()
{
}
