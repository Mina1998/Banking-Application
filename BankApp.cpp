#include "pch.h"
#include "BankApp.h"
#include "SavingBankAcc.h"
#include "BankAcc.h"
#include "client.h"
#include <iostream>
#include <string>

using namespace std;


bool BankApp::findAccountbyID(string accountID, BankAcc &ba)
{
	for (int i = 0; i < accountsNum; i++)
	{
		if (accounts[i].getAccountID().compare(accountID) == 0) {
			ba = accounts[i];
			return true;
		}
	}

	return false;
}
		  //*************************** Constructors *************************** //
BankApp::BankApp()
		  {
			  accountsNum = 0;
			  clients = new client[1000];
			  accounts = new BankAcc[1000];
		  }

		  //*************************** member functions *************************** //
void BankApp::start()
{
			  int choice;
			  do {
				  cout << " Welcome to FCI Banking Application" << endl;
				  cout << "1. Create a new account" << endl;
				  cout << "2. List Clients and Accounts" << endl;
				  cout << "3. Withdraw Money" << endl;
				  cout << "4. Deposit Money" << endl;
				  cout << "5. EXIT" << endl;
				  cout << "Please Enter Your Choice ====> ";
				  cin >> choice;

				  cout << endl << endl;

				  if (choice == 1)
				  {
					  // get required data
					  string clientName, clientAddress, clientPhoneNumber;
					  int accountType;
					  double startingBalance;

					  cout << "Please Enter Client Name ====> ";
					  cin.ignore();
					  getline(cin, clientName);

					  cout << "\nPlease Enter Client Address ====> ";
					  getline(cin, clientAddress);

					  cout << "\nPlease Enter Client Phone ====> ";
					  getline(cin, clientPhoneNumber);

					  cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 ====> ";
					  cin >> accountType;
					  while (accountType != 1 && accountType != 2)
					  {
						  cout << "Invalid Account Type, Try Again" << endl;
						  cin >> accountType;
					  }

					  cout << "\nPlease Enter the Starting Balance ====> ";
					  cin >> startingBalance;
					  while (startingBalance < 0.0)
					  {
						  cout << "ERROR! Balance can't be negative. Please Try Again ===>" << endl;
						  cin >> startingBalance;
					  }

					  // call function
					  createNewAccount(clientName, clientAddress, clientPhoneNumber, accountType, startingBalance);


				  }
				  else if (choice == 2)
					  listClientsAndAccounts();
				  else if (choice == 3) {

					  string accountID;

					  cout << "Please Enter Account ID ====> ";
					  cin >> accountID;

					  withdrawMoney(accountID);
				  }
				  else if (choice == 4) {

					  string accountID;

					  cout << "Please Enter Account ID ====> ";
					  cin >> accountID;

					  depositMoney(accountID);
				  }
				  else if (choice == 5)
					  cout << endl << "******** Thank you for using FCI Banking System ********" << endl << endl;

				  cout << endl << endl;

			  } while (choice != 5);


		  }
bool BankApp::createNewAccount(string clientName, string clientAddress, string clientPhoneNumber, int accountType, double startingBalance)
		  {

			  BankAcc* ba;
			  client* c;

			  bool validOperation = true;

			  if (accountType == 1) {

				  ba = new BankAcc;
				  ba->setAccountType("Basic");

			  }
			  else
			  {

				  ba = new SavingBankAcc;

				  if (startingBalance < ba->getMinimumBalance()) {

					  validOperation = false;

					  cout << endl << "ERROR! The Minimum Balance Should be : " << ba->getMinimumBalance() << endl
						  << "Sorry this is invalid operation" << endl;
				  }

			  }

			  if (validOperation) {

				  ba->setBalance(startingBalance);
				  ba->setAccountType("Savings");

				  c = new client(clientName, clientAddress, clientPhoneNumber);
				  ba->setClient(c);
				  ba->setAccountID(accountsNum + 1);

				  c->setBankAccount(ba);

				  // add the new account and client to the lists
				  accounts[accountsNum] = *ba;
				  clients[accountsNum] = *c;

				  accountsNum++;


				  cout << "An account was created with ID " << ba->getAccountID() << " and Starting Balance "<< startingBalance << " L.E." << endl;

				  delete c;
			  }

			  delete ba;


			  return  validOperation;
		  }
void BankApp::listClientsAndAccounts()
{

			  cout << "Accounts Num : " << accountsNum << endl;
			  for (int i = 0; i < accountsNum; i++)
			  {
				  BankAcc ba = accounts[i];
				  client c = clients[i];

				  cout << endl;
				  cout << "---------------------------- " << c.getName() << " ----------------------------" << endl;
				  cout << "Address : " << c.getAddress() << "\t" << "Phone : " << c.getphoneNumber() << endl;
				  cout << "Account ID : " << ba.getAccountID() << endl;
				  cout << "Balance : " << ba.getBalance() << endl;

			  }
}
void BankApp::withdrawMoney(string accountID)
{
			  BankAcc ba;
			  bool found = findAccountbyID(accountID, ba);

			  if (!found)
				  cout << endl << "ERROR! No Such Account Exists." << endl;
			  else {

				  cout << "Account ID : " << ba.getAccountID() << endl;
				  cout << "Account Type : " << ba.getAccountType() << endl;
				  cout << "Balance : " << ba.getBalance() << endl;

				  double amount;
				  cout << "Please Enter The Amount to Withdraw ====>";
				  cin >> amount;

				  ba.withDraw(amount);
				  cout << "Thank You." << endl;
				  cout << "Account ID : " << ba.getAccountID() << endl;
				  cout << "New Balance : " << ba.getBalance() << endl;

			  }
}
void BankApp::depositMoney(string accountID)
{
			  BankAcc ba;
			  bool found = findAccountbyID(accountID, ba);

			  if (!found)
				  cout << endl << "ERROR! No Such Account Exists." << endl;
			  else {

				  cout << "Account ID : " << ba.getAccountID() << endl;
				  cout << "Account Type : " << ba.getAccountType() << endl;
				  cout << "Balance : " << ba.getBalance() << endl;

				  double amount;
				  cout << "Please Enter The Amount to Deposit ====>";
				  cin >> amount;

				  ba.deposit(amount);
				  cout << "Thank You." << endl;
				  cout << "Account ID : " << ba.getAccountID() << endl;
				  cout << "New Balance : " << ba.getBalance() << endl;

			  }
}
BankApp::~BankApp()
{
}
