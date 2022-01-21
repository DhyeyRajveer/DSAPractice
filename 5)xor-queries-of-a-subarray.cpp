/*
Given an array and some ranges for that array,
we hv to find the XOR of elements in those ranges
Optimal solution:
We create a vector(ref) which contains XOR till ith elements
So ref.[i] = a[0]^a[1]^a[2]...a[i]
For query [L,R], ans = ref[R] ^ ref[L-1]
It works cuz ref[L-1] removes all elements b4 L cuz a^a = 0 & a^b^c = a^c^b..
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> refer{arr[0]};
        vector<int> ans;
        for(int i=1;i<arr.size();i++) refer.push_back(refer[i-1]^arr[i]);
        for(auto x:queries)
        {
             int L = x[0], R = x[1];
             if(L!=0) ans.push_back(refer[R]^refer[L-1]);
             else ans.push_back(refer[R]);
        }
        return ans;
    }
};

int main()
{
     Solution sol;
     vector<int> arr{1,3,4,8};
     vector<vector<int>> queries{{0,1},{1,2},{0,3},{3,3}};
     vector<int> ans = sol.xorQueries(arr, queries);
     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	return 0;
}
