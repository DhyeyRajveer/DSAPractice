/*
We r given thre ints, a b c
We hv to find the minimum flips req to make a OR b = c
So, my approach
We will go from 0th bit to the last bit for c
Now there will be two cases, one it is 0 or two, that it is one
If it is 0 we would hv to make sure that both of them r 0
If it is 1 we would hv to make sure that atleat one of em is 1
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int a, int b, int c)
    {
         int counter = 0;
         for(int i=0;i<32;i++)
         {
              bool cb = (1<<i)&c, ab = (1<<i)&a, bb = (1<<i)&b;
              if(cb==1)
              {
                   if(bb==1 || ab==1) continue;
                   else counter++;
              }
              else
              {
                   if(bb==1) counter++;
                   if(ab==1) counter++;
              }
         }
    }
};

int main()
{
     Solution sol;
     vector<int> arr{1,3,4,8};
     vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
     int a = 2, b= 6, c = 5;
     vector<int> ans = sol.func(a, b, c);
     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
     return 0;
}
