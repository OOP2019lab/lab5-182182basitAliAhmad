#include "BankAccount.h"


void main()
{
	BankAccount myAccount("John Doe" , 549002);

	myAccount.deposit(1000);
	myAccount.withDraw(2000);
	
	myAccount.printAccount();
}
