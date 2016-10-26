//
//  main.cpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//
//EX05_01 – Liang Programming Exercise 12.2: Linear Search
//EX05_02 – Liang Programming Exercise 12.4: Is sorted?
//EX05_03 – Liang Programming Exercise 12.8: Implement vector class
//EX05_04 – Liang Programming Exercise 12.20: Shuffle vector
//EX05_05 – Liang Programming Exercise 12.25: new Account class

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

#include "LinearSearch.hpp"
#include "IsSorted.hpp"
//#include "Vector.hpp"
//#include "ShuffleVector.hpp"
#include "Account.hpp"



int main()
{
    //EX05_01 – Liang Programming Exercise 12.2: Linear Search
    testSearch();
    
    cout << " " <<endl;
    
    //EX05_02 – Liang Programming Exercise 12.4: Is sorted?
    sortComplete();
    
    cout << " " <<endl;
    
    //EX05_05 – Liang Programming Exercise 12.25: new Account class
    
    Account A1;
    A1.setName("Joe");
    A1.setId(1234);
    A1.setBalance(100000);
    A1.setAnnualInterestRate(.5);
    A1.deposit(50);
    A1.deposit(60);
    A1.deposit(70);
    A1.withdraw(10);
    A1.withdraw(5);
    A1.withdraw(1);
    
    //ADD TRANSACTIONS
    cout<<"Name:" << A1.getname()<<endl;
    cout<<"Balance: $"<<A1.getbalance()<<endl;
    cout <<"Monthly Interest: $"<< A1.getMonthlyInterestRate()<<endl;
    cout <<"Total Balance a month: $"<< A1.getbalance()+ A1.getMonthlyInterestRate()<<endl;
    
    return 0;
    
}

