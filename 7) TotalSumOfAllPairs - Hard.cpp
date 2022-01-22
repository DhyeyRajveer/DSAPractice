/*
Given: An array
To find: Sum of XOR of each possible pair (A1^A2 and A2^A1 are same pair and so will be counted only once)
Given a1 a2 a3 a4
ans = a1a2 + a1a3 + a1a4 + a2a3 + a2a4 + a3a4
= [SIGMA]2**i(Total number of time ith bit is set, considering all pairs)
so in the end we hv to find the number of times each bit is set in each pair's XOR
That equals (number of 0s in ith position) * (number of 1s in ith position)
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SumOfAllPairs(vector<int> arr)
    {
         int result = 0;
         for(int i=0;i<32;i++)
         {
              int numz = 0, numo = 0;
              for(int j=0;j<arr.size();j++)
              {
                   if(arr[j] & (1<<i)) numo++;
                   else numz++;
              }
              result += (1<<i) * (numz*numo);
         }
         return result;
    }
};

int main()
{
     Solution sol;
     vector<int> arr{1,3,4,8};
     vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
     int ans = sol.SumOfAllPairs(arr);
     //for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
     cout<<ans<<endl;
     return 0;
}
