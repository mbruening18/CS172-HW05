//
//  main.cpp
//  CS172HW#05 Vector
//
//  Created by Megan Bruening on 11/1/16.
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
using namespace std;

//EX05_01 – Liang Programming Exercise 12.2: Linear Search
//compares the key to each element in the array
template<typename A>
int linearSearch(const A list[], A key, int arraySize)
{
    for(int i=0; i<arraySize; i++)
    {
        if(key==list[i])
            return i;
    }
    return -1;
}

void testSearch()
{
    //uses an int
    int list1[]={1,2,3,4,5};
    //checks to see if in the array there is an 8
    if( linearSearch(list1, 8, 5) == -1)
    {
        cout<<"No match"<<endl;
    }
    else
    {
        cout<<"Match"<<endl;
    }
    
    //uses a double
    double list2[]={1.5,4.5,10.5,2.7};
    //checks to see if in the array there is a 1.5
    if( linearSearch(list2, 1.5, 4) == -1)
    {
        cout<<"No match"<<endl;
    }
    else
    {
        cout<<"Match"<<endl;
    }
    
    //uses a string
    string list3[]={"Joe","Megan","Heidi","Andrew"};
    //checks to see if in the array there is a Jim
    if( linearSearch(list3, string("Jim"), 4) == -1)
    {
        cout<<"No match"<<endl;
    }
    else
    {
        cout<<"Match"<<endl;
    }
    
}



//EX05_02 – Liang Programming Exercise 12.4: Is sorted?

//Checks to see if the elements in the array are sorted
template<typename B>
bool isSorted(const B list[], int size)
{
    if (size==1)
    {
        return true;
    }
    
    for ( int i=0; i<size-1; i++)
    {
        if ( list[i] > list[i+1])
        {
            return false;
        }
    }
    return true;
}

//tests the array
template<typename C>
void testArray(const C list[], int size)
{
    //array are sorted
    for (int i=0; i< size; i++)
    {
        cout<< list[i]<<" ";
    }
    cout<< endl;
}

void sortComplete()
{
    //uses an int
    //takes an array
    int list1[]={1,2,3,4,5,6};
    //checks list1
    isSorted(list1, 6);
    testArray(list1, 6);
    //outputs if it is sorted
    if ( isSorted(list1, 6))
    {
        cout << "This list is sorted" << endl;
    }
    else
    {
        cout << "This list is not sorted" << endl;
    }
    
    cout << " " <<endl;
    
    //uses a double
    //takes an array
    double list2[]={.4,2.4, 6.7, 7.3,8.6,8.7};
    //checks list2
    isSorted(list2, 6);
    testArray(list2, 6);
    //outputs if it is sorted
    if ( isSorted(list2, 6))
    {
        cout << "This list is sorted" << endl;
    }
    else
    {
        cout << "This list is not sorted" << endl;
    }
    
    cout << " " <<endl;
    
    //uses a string
    //takes an array
    string list3[] = {"Heidi", "Megan", "Joe", "Andrew", "Erin"};
     //checks list3
    isSorted(list3, 5);
    testArray(list3, 5);
    //outputs if it is sorted
    if ( isSorted(list3, 5))
    {
        cout << "This list is sorted" << endl;
    }
    else
    {
        cout << "This list is not sorted" << endl;
    }
}


//EX05_03 – Liang Programming Exercise 12.8: Implement vector class
//created a class Vector
template <typename D>
class Vector
{
    //makes elements private
private:
    //declares variables
    D* mElements;
    int mSize;
    int mCapacity;
    void doubleCapacity()
    {
        D *old = mElements;
        mCapacity = 2 * mCapacity;
        mElements = new D[ mCapacity ];
        for ( int i=0; i<mSize; i++ )
        {
            mElements[i] = old[i];
        }
        delete [] old;
    }
    //makes elements public
public:
    //no-arg constructor
    Vector()
    {
        mCapacity = 8;
        mSize = 0;
        mElements = new D[mCapacity];
    }
    //arg constructor
    Vector(int size)
    {
        mCapacity = size;
        mSize = size;
        mElements = new D[mCapacity];
        
    }
    //arg constructor
    Vector(int size, D defaultValue)
    {
        mCapacity = size;
        mSize = size;
        mElements = new D[mCapacity];
        for (int i = 0; i < mSize; i++)
        {
            mElements[i] = defaultValue;
        }
    }
    //pushback an element
    void pushBack(D element)
    {
        if (mSize >= mCapacity)
        {
            doubleCapacity();
        }
        //returns element and increments size ++
        mElements[mSize] = element;
        mSize++;
    }
    
    void popBack()
    {
        //increments size --
        mSize--;
    }
    
    //returns mSize
    unsigned int size() const
    {
        return mSize;
    }
    
    //returns element and and index array
    D at(int index) const
    {
        return mElements[index];
    }
    
    //emptys returns size == to 0
    bool empty() const
    {
        return mSize == 0;
    }
    
    //clears sixe =0
    void clear()
    {
        mSize = 0;
    }
    
    //clears and swaps
    void swap(Vector<D> v2)
    {
        clear();
        for (int i = 0; i < v2.size(); i ++)
        {
            pushBack(v2.at(i));
        }
    }
    
};



 //EX05_04 – Liang Programming Exercise 12.20: Shuffle vector

//empelents Shuffle vector
 template <typename E>
 void shuffleVector(vector<E>& v)
 {
     //makes random
     srand((unsigned int)time(NULL));
     for(int i=0; i<v.size(); i++)
     {
         int index = rand() % v.size();
         E temp = v[index];
         v[index]=v[i];
         v[i]=temp;
     }
 }

//EX05_05 – Liang Programming Exercise 12.25: new Account class

//declares class Account
class Account
{
    //makes public
public:
    //Declares variables
    int id;
    double balance;
    double annualInterestRate;
    string name;
    
    //arg constructor takes ID, BALANCE, AnnualIntreatRate
    Account(int ID, double BALANCE, double AnnualIntrestRate)
    {
        id=ID;
        balance=BALANCE;
        annualInterestRate=AnnualIntrestRate;
    }
    
    //sets id, balance, annualInterestRate to nominal numbers
    Account()
    {
        id=1234;
        balance=2000;
        annualInterestRate=5;
    }
    
    //gets name and returns name
    string getname()
    {
        return name;
    }
    
    //gets balance and returns balance
    double getbalance()
    {
        return balance;
    }
    
    //gets annualInterestRate and returns annualInterestRate divided by 12 months
    double getannualInterestRate()
    {
        return (annualInterestRate*balance)/12;
    }
    
    //gets id and returns id
    int getid()
    {
        return id;
    }
    
    //strings Name and sets name
    void setName(string NAME)
    {
        name=NAME;
    }
    
    // double theBalance and sets balance
    void setBalance(double theBalance)
    {
        balance=theBalance;
    }
    
    //double theAnnualInterestRate and sets annualInterestRate
    void setAnnualInterestRate(double theAnnualInterestRate)
    {
        annualInterestRate=theAnnualInterestRate;
    }
    
    //declares theId and sets to id
    void setId(int theId)
    {
        id=theId;
    }
    
    //gets the monthly intrest rate/ by 12 months
    int getMonthlyInterestRate()
    {
        return (annualInterestRate*balance)/12;
    }
    
    //withdraws money subtracts from amount
    void withdraw(int amount)
    {
        balance -= amount;
    }
    
    //deposites money adds from amount
    void deposit(int amount)
    {
        balance += amount;
    }
    
};


int main()
{
    //EX05_01 – Liang Programming Exercise 12.2: Linear Search
    cout << "//12.2: Linear Search" <<endl;
    
    //calls and implements function
    testSearch();
    
    cout << " " <<endl;
    
    
    
    
    
    //EX05_02 – Liang Programming Exercise 12.4: Is sorted?
    cout << "//12.4: Is sorted?" <<endl;
    
    //calls and implements function
    sortComplete();
    
    cout << " " <<endl;
    
    
    
    
    
    //EX05_03 – Liang Programming Exercise 12.8: Implement vector class
    cout << "//12.8: Implement vector class" <<endl;
    
    //uses Vector integer
    Vector<int> vInt;
    
    //pushback i+1
    for(int i=0; i<10; i++)
    {
        vInt.pushBack(i+1);
    }
    
    //couts numbers in the vector
    cout<<"Numbers in the vector: ";
    //uses function at
    for(int i=0; i<vInt.size(); i++)
    {
        cout<<vInt.at(i)<<" ";
    }
    
    cout << " " <<endl;
    
    //uses Vector String
    Vector<string> vString;
    
    //pushesback string, takes it in
    vString.pushBack("Portland");
    vString.pushBack("Houston");
    vString.pushBack("New Jersey");
    vString.pushBack("Spokane");
    
    //couts the strings in the vector string
    cout<<"Strings in the string vector: ";
    for(int i=0; i< vString.size(); i++)
    {
        cout<<vString.at(i)<< ", ";
    }
    
    cout << " " <<endl;
    //popbacks vector string
    vString.popBack();
    
    //Uses 2nd vector string
    Vector<string> v2;
    
    //swaps last for new string
    v2.swap(vString);
    v2.pushBack("Atlanta");
    
    ///couts the strings in the vector string
    cout<<"Strings in the vector v2: ";
    for(int i=0; i< v2.size(); i++)
    {
        cout<< v2.at(i)<< ", ";
    }
    cout << " " <<endl;
    cout << " " <<endl;
    
    
    
    
   
    //EX05_04 – Liang Programming Exercise 12.20: Shuffle vector
    cout << "//12.20: Shuffle vector" <<endl;
    
    //uses Vector integer at number 10
    vector<int> number(10);
    
    //takes 10 integers
    for(int i=0; i < number.size(); i++)
    {
        number[i] = i;
    }
    for(int i=0; i < number.size(); i++)
    {
        cout << number[i] << " ";
        
    }cout << endl;
    //shuffles the numbers random
    shuffleVector(number);
    //couts the rand numbers
    for(int i=0; i < number.size(); i++)
    {
        cout<< number[i] << " ";
    }
    
    
    cout << " " <<endl;
    cout << " " <<endl;
    
    
    
    
    
    //EX05_05 – Liang Programming Exercise 12.25: new Account class
    cout << "//12.25: new Account class" <<endl;
    
    //declares account to A1
    Account A1;
    //sets name on account
    A1.setName("Megan");
    ////sets id on account
    A1.setId(1234);
    //sets balance on account
    A1.setBalance(100000);
    //sets annual intrest rate on account
    A1.setAnnualInterestRate(.5);
    //deposits money adds to account
    A1.deposit(5030);
    A1.deposit(20000);
    A1.deposit(902);
    //withdraws money subtracts from account
    A1.withdraw(10);
    A1.withdraw(5);
    A1.withdraw(2);
    
    //couts the name, balance, monthly intrest, and total balance
    cout<<"Name: " << A1.getname()<<endl;
    cout<<"Balance: $"<<A1.getbalance()<<endl;
    cout <<"Monthly Interest: $"<< A1.getMonthlyInterestRate()<<endl;
    cout <<"Total Balance: $"<< A1.getbalance()+ A1.getMonthlyInterestRate()<<endl;
    
    cout << " " <<endl;
    
    
    
    
    
    return 0;
}
