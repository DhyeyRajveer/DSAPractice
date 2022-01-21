/*
First methos is ez!! no explaination
Second method
okay so 16 is 10000 and 15 is 011111, 10000 - (1) = 01111
In the same way... 101010{100} - (1) = 101010{011} - (1) = 101010{010}
So with every substraction last set bit becomes 0 and all bits after it become set
Sooo if we do AND op of n and n-1, last bit set bit is removed....
So we keep removing the last set bit and keep counting it till no set bit remains..
eg, n becomes 0
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int q=0,n=0,f=0;
     cin>>q;
     while(q--)
     {
          cin>>n;
          int cnt=0;
          f = 1;
          /*while(n>0)
          {
               if(n&f == 1) cnt++;
               n=n>>1;
          }*/
          while(n>0)
          {
               cnt++;
               f = n-1;
               n = n&f;
          }
          cout<<"Set bits are "<<cnt<<endl;
     }
	return 0;
}
