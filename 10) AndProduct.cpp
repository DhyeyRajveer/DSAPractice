/*
We are given a range of natural numbers,
We have to figure out the end product of all the numbers in that range
So lets try to find the solution bit by bit
Now what conditions must be met for the ith bit in our answer to be set?
Every bit should be set in range be set right?
Now an interesting observation, see the last bit from 1 to ....
It would be in series 0 1 0 1 0 1 0 1.. Now look at the second bit...
0 0 1 1 0 0 1 1... And third? 0 0 0 1 1 1 0 0 0 1 1 1.... And the series would continue...
Lets call continuous series of 1s as pack...
Why is it like that? Because at the end of the pack,
We hv reached the maximum value a bit can generate... It happens to every bit
Until we reach the last bit, after which if we wanna go ahead, we gotta add one more bit and start all over...
Back to the question, lets call the number of elements in range as d and pack size as p
for each bit, if d is more then p, we r sure to hv a 0, so ith bit in result will be 0
If it is less then d, then we hv to check if ith bit of start and ith bit of end is set
if yes then the result will also hv it set bcuz we r sure that range numbers are less then p
and therefore there is no chance of another 0 pack comin inbetween
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long andProduct(long a, long b)
    {
         long d = b - a + 1, ans=0;
         for(int i=0;i<32;i++)
         {
              long f = 1;
              int p = f<<i;
              if(d>p) continue;
              else
              {
                   if((a&(f<<i)) && (b&(f<<i))) ans += f<<i;
                   else continue;
              }
         }
         return ans;
    }
};

int main()
{
     Solution sol;
     vector<int> arr{1,3,4,8};

     return 0;
}
