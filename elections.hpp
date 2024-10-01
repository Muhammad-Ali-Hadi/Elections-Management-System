#ifndef _ELECTION_HPP_
#define _ELECTION_HPP_
#pragma once
#include<bits/stdc++.h>
using namespace std;

bool validateCNIC(string CNIC)
{
    if(CNIC.size()==15 && CNIC.at(5) == '-' && CNIC.at(13) == '-')
    {   
        for(int i=0;i<CNIC.size();i++)
        {
            if(CNIC.at(i)<48 && CNIC.at(i)>57)
            {
                return false;
            }
        }
        return true;
    }
    else
    return false;
}
#endif