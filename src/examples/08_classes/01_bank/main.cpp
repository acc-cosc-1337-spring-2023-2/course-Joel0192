#include<iostream>
#include<time.h>
#include "checking_account.h"

using std::cout;

int main()
{
	srand(time(NULL));//generate true randoms on each main run execution

	CheckingAccount account;//cust 1
	cout<<"Balance: "<<account.get_balance()<<"\n";

	CheckingAccount account1(100);//cust 2
	cout<<"Balance: "<<account1.get_balance()<<"\n";
	return 0;
}