//
//  LinearSearch.cpp
//  CS172-HW05
//
//  Created by Megan Bruening on 10/26/16.
//  Copyright © 2016 Megan Bruening. All rights reserved.
//


#include "LinearSearch.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <string>
#include <fstream>
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



/*
vector()
{
    Vector<int> Vector;
    
    for(int i=0; i<10; i++)
    {
        intVector.push_back(i+1);
    }
    
    cout<<"Numbers in the vector: ";
    for(int i=0; i<intVector.size(); i++)
    {
        cout<<intVector[i]<<" ";
    }
    
    Vector<string> stringVector;
    
    string Vector.pushBack("Megan");
    string Vector.pushBack("Joe");
    string Vector.pushBack("Erin");
    string Vector.pushBack("Heidi");
    
    cout<<"Strings in the string vector: "<<endl;
    for(int i=0; i< stringVector.size(); i++)
    {
        cout<<stringVector[i]<< " ";
    }
    
    string Vector.pop_back();
    
    vector<string> v2;
    v2.swap(stringVector);
    v2[0]="Megan";
    
    cout<<"Strings in the vector v2: "<<endl;
    for(int i=0; i< v2.size(); i++)
    {
        cout<< v2.at(i)<< " ";
    }
}
*/



