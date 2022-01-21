/*
Given: a array of integers(arr){4,3,9,1}
We hv to find XOR of sum of each pair possible in arr
So we hv to find (4+4)^(4+3)^(4,9)^(4,1) ^ (3,4)^(3,3)^.....
It can be seen that each pair has a counter except (4,4) (3,3) (9,9) (1,1)
For every pair like (4,3) there is (3,4)
So they would cancel out and all we would need to do is find XOR of double of each element
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int allPairSumXOR(vector<int> arr)
    {
         int ans=0;
         for(auto x:arr) ans ^= x*2;
         return ans;
    }
};

int main()
{
     Solution sol;
     vector<int> arr{2,4,1};
     vector<vector<int>> arr2{{0,1},{1,2},{0,3},{3,3}};
     auto ans = sol.allPairSumXOR(arr);
     cout<<ans<<" ";
     return 0;
}
