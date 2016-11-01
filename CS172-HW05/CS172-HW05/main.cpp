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
#include <cctype>
#include <vector>

#include "LinearSearch.hpp"
#include "IsSorted.hpp"
#include "Vector.hpp"
#include "ShuffleVector.hpp"
#include "Account.hpp"



int main()
{
    //EX05_01 – Liang Programming Exercise 12.2: Linear Search
    cout << "//12.2: Linear Search" <<endl;
    testSearch();
    
    cout << " " <<endl;
    
    //EX05_02 – Liang Programming Exercise 12.4: Is sorted?
    cout << "//12.4: Is sorted?" <<endl;
    sortComplete();
    
    cout << " " <<endl;
    
    //EX05_03 – Liang Programming Exercise 12.8: Implement vector class
     cout << "//12.8: Implement vector class" <<endl;
    
    Vector<int> vInt;
    
    for(int i=0; i<10; i++)
    {
        vInt.pushBack(i+1);
    }
    
    cout<<"Numbers in the vector: ";
    for(int i=0; i<vInt.size(); i++)
    {
        cout<<vInt.at(i)<<" ";
    }
    
    Vector<string> vString;
    
    vString.pushBack("Dallas");
    vString.pushBack("Houston");
    vString.pushBack("Austin");
    vString.pushBack("Norman");
    
    cout<<"Strings in the string vector: ";
    for(int i=0; i< vString.size(); i++)
        cout<<vString.at(i)<< " ";
    
    vString.popBack();
    
    Vector<string> v2;
    
    v2.swap(vString);
    v2.pushBack("Atlanta");
    
    cout<<"Strings in the vector v2: ";
    for(int i=0; i< v2.size(); i++)
    {
        cout<< v2.at(i)<< " ";
    }
}

    cout << " " <<endl;
    
    //EX05_04 – Liang Programming Exercise 12.20: Shuffle vector
    cout << "//12.20: Shuffle vector" <<endl;

    vector<int> nums(10);
    //cout << "Enter 10 integers: ";
    for(int i=0; i < nums.size(); i++)
    {
        nums[i] = i;
    }
    for(int i=0; i < nums.size(); i++)
    cout << nums[i] << " ";
    cout << endl;
    shuffle(nums);
    for(int i=0; i < nums.size(); i++)
    cout<< nums[i] << " ";
    cout << endl;




    cout << " " <<endl;

    //EX05_05 – Liang Programming Exercise 12.25: new Account class
    cout << "//12.25: new Account class" <<endl;
    
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
    
    cout << " " <<endl;
    return 0;
    
}

