/*
To find the ith bit , from left, from 0. Whether its set or not..
int f = 00000001, n = 01010100, i = 4 (=1)
f<<4 = 00010000
Soooooo
      01010100
&(AND)00010000
     =00010000
SOOO if ith bit was 0 it would hv been 0 too!!!!
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q = 0, n=0, i=0;
    cin>>q;
    while(q--)
    {
         // To find the ith bit
         cin>>n>>i;
         int f=1;
         f = f<<i;
         int result = n & f;
         if(result==0) cout<<"ith bit is 0"<<endl;
         else cout<<"ith bit is 1"<<endl;
    }
    return 0;
}
