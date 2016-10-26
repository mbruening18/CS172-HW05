//
//  Account.hpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

//EX05_05 – Liang Programming Exercise 12.25: new Account class

class Account
{
public:
    int id;
    double balance;
    double annualInterestRate;
    string name;
    
    Account(int, double, double);
    Account();
    
    string getname();
    double getbalance();
    double getannualInterestRate();
    int getid();
    
    void setName(string);
    void setBalance(double);
    void setAnnualInterestRate(double);
    void setId(int);
    
    int getMonthlyInterestRate();
    void withdraw(int);
    void deposit(int);
    
};
#endif /* Account_hpp */
