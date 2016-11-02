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
    //int
    int list1[]={1,2,3,4,5};
    if( linearSearch(list1, 8, 5) == -1)
    {
        cout<<"No match"<<endl;
    }
    else
    {
        cout<<"Match"<<endl;
    }
    
    //double
    double list2[]={1.5,4.5,10.5,2.7};
    if( linearSearch(list2, 1.5, 4) == -1)
    {
        cout<<"No match"<<endl;
    }
    else
    {
        cout<<"Match"<<endl;
    }
    
    //string
    string list3[]={"Joe","Megan","Heidi","Andrew"};
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
    int list1[]={1,2,3,4,5,6};
    isSorted(list1, 6);
    testArray(list1, 6);
    if ( isSorted(list1, 6))
    {
        cout << "This list is sorted" << endl;
    }
    else
    {
        cout << "This list is not sorted" << endl;
    }
    
    cout << " " <<endl;
    
    double list2[]={.4,2.4, 6.7, 7.3,8.6,8.7};
    isSorted(list2, 6);
    testArray(list2, 6);
    
    if ( isSorted(list2, 6))
    {
        cout << "This list is sorted" << endl;
    }
    else
    {
        cout << "This list is not sorted" << endl;
    }
    
    cout << " " <<endl;
    
    string list3[] = {"Heidi", "Megan", "Joe", "Andrew", "Erin"};
    isSorted(list3, 5);
    testArray(list3, 5);
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
template <typename T>
class Vector
{
private:
    T* mElements;
    int mSize;
    int mCapacity;
    void doubleCapacity()
    {
        T *old = mElements;
        mCapacity = 2 * mCapacity;
        mElements = new T[ mCapacity ];
        for ( int i=0; i<mSize; i++ )
        {
            mElements[i] = old[i];
        }
        delete [] old;
    }
public:
    Vector()
    {
        mCapacity = 8;
        mSize = 0;
        mElements = new T[mCapacity];
    }
    
    Vector(int size)
    {
        mCapacity = size;
        mSize = size;
        mElements = new T[mCapacity];
        
    }
    
    Vector(int size, T defaultValue)
    {
        mCapacity = size;
        mSize = size;
        mElements = new T[mCapacity];
        for (int i = 0; i < mSize; i++)
        {
            mElements[i] = defaultValue;
        }
    }
    
    void pushBack(T element)
    {
        if (mSize >= mCapacity)
        {
            doubleCapacity();
        }
        mElements[mSize] = element;
        mSize++;
    }
    
    void popBack()
    {
        mSize--;
    }
    
    unsigned int size() const
    {
        return mSize;
    }
    
    T at(int index) const
    {
        return mElements[index];
    }
    
    bool empty() const
    {
        return mSize == 0;
    }
    
    void clear()
    {
        mSize = 0;
    }
    
    void swap(Vector<T> v2)
    {
        clear();
        for (int i = 0; i < v2.size(); i ++)
        {
            pushBack(v2.at(i));
        }
        
    }
    
};


/*
 //EX05_04 – Liang Programming Exercise 12.20: Shuffle vector
 
 void testShuffle()
 {
 vector<int> myvector;
 
 const int maxSize=10;
 int x=0;
 for (int i=0; i<maxSize; ++i)
 {
 cout << "Enter integer element #" << i << ":";
 cin >>x;
 }
 
 // using built-in random generator:
 cout << "Original Vector:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myvector[i] << endl;
 }
 
 shuffle ( myvector );
 cout << "Vector after first shuffle:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myvector[i] << endl;
 }
 
 // using myrandom:
 shuffle ( myvector );
 cout << "Vector after second shuffle:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myvector[i] << endl;
 }
 }
 
 
 void testShuffle()
 {
 Vector<int> myVector;
 
 const int maxSize=10;
 int x=0;
 for (int i=0; i<maxSize; ++i)
 {
 cout << "Enter integer element #" << i << ":";
 cin >>x;
 }
 
 // using built-in random generator:
 cout << "Original Vector:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myVector[i] << endl;
 }
 
 shuffle ( myVector );
 cout << "Vector after first shuffle:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myvector[i] << endl;
 }
 
 // using myrandom:
 shuffle ( myVector );
 cout << "Vector after second shuffle:" << endl;
 for(int i=0; i<maxSize; i++)
 {
 cout << "myvector[" << i << "]=" << myVector[i] << endl;
 }
 }
 
 */
//EX05_05 – Liang Programming Exercise 12.25: new Account class

class Account
{
public:
    int id;
    double balance;
    double annualInterestRate;
    string name;
    
    Account(int ID, double BALANCE, double AnnualIntrestRate)
    {
        id=ID;
        balance=BALANCE;
        annualInterestRate=AnnualIntrestRate;
    }
    Account()
    {
        id=1234;
        balance=2000;
        annualInterestRate=5;
    }
    
    string getname()
    {
        return name;
    }
    double getbalance()
    {
        return balance;
    }
    double getannualInterestRate()
    {
        return (annualInterestRate*balance)/12;
    }
    int getid();
    
    void setName(string NAME)
    {
        name=NAME;
    }
    void setBalance(double theBalance)
    {
        balance=theBalance;
    }
    void setAnnualInterestRate(double theAnnualInterestRate)
    {
        annualInterestRate=theAnnualInterestRate;
    }
    void setId(int theId)
    {
        id=theId;
    }
    
    int getMonthlyInterestRate()
    {
        return (annualInterestRate*balance)/12;
    }
    
    void withdraw(int amount)
    {
        balance -= amount;
    }
    
    void deposit(int amount)
    {
        balance += amount;
    }
    
};


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
    cout << " " <<endl;
    
    /*
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
     */
    
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
