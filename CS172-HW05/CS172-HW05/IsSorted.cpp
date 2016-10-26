//
//  IsSorted.cpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//

#include "IsSorted.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

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
