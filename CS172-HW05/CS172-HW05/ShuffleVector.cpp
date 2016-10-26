//
//  ShuffleVector.cpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//

#include "ShuffleVector.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

//EX05_04 – Liang Programming Exercise 12.20: Shuffle vector


/*
template<typename D>
void shuffle(vector<D>& v)
{
    srand(time(NULL));
    
    int size=v.size();
    
    for ( int i=0; i< size; i++ )
    {
        int random= (rand() % size) -1;
        int temp=v[i];
        v[i]=v[random];
        v[random]=temp;
    }
}




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
*/
