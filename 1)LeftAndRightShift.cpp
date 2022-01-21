/*
In left shift, 00010101 becomes 00101010...
Imagine 0005, now left shift it... 0050. It happens bcuz it decimal
In the same way in binary the number is multiplied by 2
So 21 becomes 42 after one shift, 84 after 2
In right shift, 21 beomes 10 after one shift (21/2)
or 5 after 2 shifts, 21/(2^2=4)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q = 0, n=0, shift=0;
    cin>>q;
    // Left shift
    /*while(q--)
    {
         cin>>n>>shift;
         cout<<n<<" << "<<(n<<shift)<<endl;
    }*/
    // Right shift....
    while(q--)
    {
        cin>>n>>shift;
        cout<<n<<" << "<<(n>>shift)<<endl;
    }


    return 0;
}
