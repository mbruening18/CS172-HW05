//
//  Account.cpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//

#include "Account.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//EX05_05 – Liang Programming Exercise 12.25: new Account class

Account::Account(int ID, double BALANCE, double AnnualIntrestRate)
{
    id=ID;
    balance=BALANCE;
    annualInterestRate=AnnualIntrestRate;
}

Account::Account()
{
    id=1234;
    balance=2000;
    annualInterestRate=5;
}

void Account::setName(string NAME)
{
    name=NAME;
}

void Account::setBalance(double theBalance)
{
    balance=theBalance;
}

void Account::setAnnualInterestRate(double theAnnualInterestRate)
{
    annualInterestRate=theAnnualInterestRate;
}

void Account::setId(int theId)
{
    id=theId;
}

string Account:: getname()
{
    return name;
}
double Account:: getbalance()
{
    return balance;
}
int Account::getMonthlyInterestRate()
{
    return (annualInterestRate*balance)/12;
}
void Account::withdraw(int amount)
{
    balance -= amount;
}
void Account::deposit(int amount)
{
    balance += amount;
}

