#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
	string accountTitle;
	int accountNumber;

	float balance;
	int balanceLimit;
	
	float* transactions;
	int capacityOfTransactions;
	int currentTransactions;

	void increaseTranCapacity();

public:
	BankAccount(string ,int );
	void printAccount();
	void withDraw(float );
	void deposit(float );
	
	~BankAccount();
};
