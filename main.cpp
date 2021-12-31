#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Account Info class

class Account_Info
{
protected:
    string name;
    string account_no;
    long int balance;
public:
    void input()
    {
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Account No. : ";
        cin>>account_no;
        cout<<"Enter Balance : ";
        cin>>balance;
    }
    virtual void display(){}

};

// Current Account class

class Current_Account: public Account_Info
{
    long int deposit;
    long int widthdraw;

public:
    virtual void widthdraw()
    {
        cout<<"Enter the amount(Widthdraw) : ";
        cin>>widthdraw;
        if(balance >=widthdraw)
        {
            balance-=widthdraw;
            cout<<"widthdraw successfull"<<endl;
        }
        else
        {
            cout<<"!! insufficient Balance !!" <<endl;
        }
    }
    void deposit()
    {
        cout<<"Enter amount(Deposit) : ";
        cin>>deposit;
        balance+=deposit;
        cout<<"Deposit Successfull"<<endl;
    }

    virtual void display()
    {
        cout<<"Name : "<<name;
        cout<<"Account Number : "<<account_no;
        cout<<"Balance : "<<balance;
    }
};

//Savings Account class

class Savings_Account:public Current_Account
{
    long int deposit_amt;
    long int sa_Irate;
public:
    void deposit()
    {
        cout<<"Enter amount(Deposit) : ";
        cin>>deposit_amt;
        balance = balance + deposit_amt + deposit_amt*(5/100);
        cout<<"Deposit Successfull"<<endl;
    }

};

//Recurring Deposit Class

class Recurring_Deposit:Current_Account
{
    long int rd_balance;
    long int deposit;
    long int rd_Irate;
    long int rd_amount;
public:
    Recurring_Deposit(long int amount,long int rate)
    {
        rd_amount = amount;
        rd_Irate = rate/100;
    }
    void deposit_RD()
    {
        balance = balance - rd_amount;
        rd_balance = rd_balance + rd_amount + rd_amount*rd_Irate;
    }

    void calculate_amt()
    {
        int no_of_months;
        cout<<"Enter RD period : "<<endl;
        cin>>no_of_months;
        cout<<"The amount after "<<no_of_months<<" will be "<<no_of_months*(rd_amount + rd_amount*rd_Irate);
    }
    void display()
    {
        cout<<"Name : "<<name;
        cout<<"Account Number : "<<account_no;
        cout<<"Main Balance : "<<balance;
        cout<<"rd Amount to be deposited(p.m) : "<<rd_amount;
        cout<<"rd Balance : "<<rd_balance;
    }

};
//Fixed Deposit Class

class Fixed_Deposit:public Account_Info
{
    long int deposit;
    long int fd_Irate;
    long int fd_amount;
    long int fd_balance;
    long int maturity_amt;
    int no_of_months;
public:
    Fixed_Deposit(long int amount,long int rate , int months)
    {
        balance = balance - fd_amount;
        fd_amount = amount;
        fd_Irate = rate/100;
        months = no_of_months;
        maturity_amt = no_of_months*(fd_amount + fd_amount*fd_Irate);
        balance = balance + maturity_amt;
    }

    void calculate_maturity_amt()
    {
        cout<<"The maturity amount after "<<no_of_months<<" will be "<< maturity_amt;
    }
 void display()
    {
        cout<<"Name : "<<name;
        cout<<"Account Number : "<<account_no;
        cout<<"Main Balance : "<<balance;
        cout<<"FD Amount deposited : "<<fd_amount;
        cout<<"Maturity Amount: "<<fd_balance;
    }

};
int main()
{
    Fixed_Deposit A(2500,5,12);
    A.display();
    _getch();
    return 0;
}