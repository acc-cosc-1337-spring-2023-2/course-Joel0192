//checking_account.h
#include<stdlib.h>

class CheckingAccount
{
public:
    CheckingAccount(){get_balance_from_db();}//default constructor
    CheckingAccount(int b) : balance(b){/*empty code block*/}
    int get_balance(){return balance;}
private:
    int balance{0};//initialize to 0
    void get_balance_from_db();
};