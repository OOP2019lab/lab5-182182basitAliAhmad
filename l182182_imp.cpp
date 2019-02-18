#include "BankAccount.h"

BankAccount::BankAccount(string name, int num) // constructor with parameters 
{
	accountTitle = name;
	accountNumber = num;

	balance = 0;
	balanceLimit = 200000;
	
	capacityOfTransactions = 10;
	transactions = new float[capacityOfTransactions];
	currentTransactions = 0;


}

void BankAccount::printAccount()
{
	cout << "Account Title: " << accountTitle << endl;
	cout << "Account Name: " << accountNumber << endl;
	cout << "Current Balance: " << balance << endl;
	for (int i = 0; i < currentTransactions; i++)
		cout << transactions[i] << endl;
	cout << "Showing " << currentTransactions << " transaction(s)" << endl;
}

void BankAccount::withDraw(float amnt)
{
	if (amnt <= balance) // check if balance is available or not
	{
		cout << "Transaction Successful!" << endl;
		balance -= amnt;

		if(currentTransactions >= capacityOfTransactions) // check if there is space available in transaction array
			increaseTranCapacity();

		transactions[currentTransactions] = -amnt;
		currentTransactions++;

	}
	else
		cout << "Transaction Unsuccessful! Insuffient balance" << endl;
}

void BankAccount::deposit(float amnt)
{
	if (balance+amnt <= balanceLimit)
	{
		cout << "Transaction Successful!" << endl;
		balance += amnt;

		if(currentTransactions >= capacityOfTransactions)
			increaseTranCapacity();

		transactions[currentTransactions] = amnt;
		currentTransactions++;
	}
	else
		cout << "deposit failed! balance limit achieved" << endl;
}

void BankAccount::increaseTranCapacity()
{
	float* temp = new float[2*capacityOfTransactions];
	for (int  i = 0; i < capacityOfTransactions; i++)
		temp[i] = transactions[i];

	delete[]transactions;
	transactions = temp;
	capacityOfTransactions *= 2; 
}

BankAccount::~BankAccount()
{
	accountTitle = "";
	accountNumber = 0;
	balance = 0;
	balanceLimit = 0;
	currentTransactions = 0;
	capacityOfTransactions = 0;
	delete[]transactions;
	transactions = nullptr;
}