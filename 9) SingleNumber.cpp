/*
Given an array,
Find the element which occurs only once whereas all other elements occur thrice
Okay so we go bit lvl again.
Lets say ith bit is set in our answer,
Then the total number of elements with ith bit set will be in the form of 3n+1
Where n is any arbitrary number.
Why? Cuz if ith bit is set in any other element, it occurs three times cuz of it...
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> arr)
    {
         vector<int> f; // Number of times ith bit is set
         for(int i=0;i<32;i++)
         {
              int counter = 0;
              for(int j=0;j<arr.size();j++)
              {
                   if(arr[j]&(1<<i)) counter++;
              }
              f.push_back(counter);
         }
         int ans = 0;
         for(int i=0;i<32;i++)
         {
              if((f[i]-1)%3==0) ans+=(1<<i);
         }
         return ans;
    }
};

int main()
{
     Solution sol;
     vector<int> arr{1,1,1,3,3,13,3,4,4,4,8,8,8};
     vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
     int ans = sol.singleNumber(arr);
     //for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
     //cout<<ans<<endl;
     cout<<(-10^-10)<<endl;
     return 0;
}
