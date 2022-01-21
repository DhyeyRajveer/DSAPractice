#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     vector<int> que{1,3,2,4};
     vector<int> ans;
     stack<int> st;
     int n = que.size();
     for(int i=0;i<n;i++)
     {
          while(st.size()!=0)
          {
               if(st.top()<que[i])
               {
                    ans.push_back(st.top());
                    break;
               }
               else st.pop();
          }
          if(st.size()==0) ans.push_back(-1);
          st.push(que[i]);
     }
     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	return 0;
}
