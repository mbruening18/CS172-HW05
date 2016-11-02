//
//  main.cpp
//  CS172-HW#05
//
//  Created by Megan Bruening on 11/1/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cctype>
#include <vector>
using namespace std;

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

int main()
{
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
