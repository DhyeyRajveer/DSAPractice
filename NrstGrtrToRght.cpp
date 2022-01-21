#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    vector<int> que{1,3,0,0,1,2,4};
    int n = 7;
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
         while(st.size()!=0)
         {
              if(st.top()>que[i])
              {
                   ans.push_back(st.top());
                   break;
              }
              else st.pop();
         }
         if(st.size()==0) ans.push_back(-1);
         st.push(que[i]);
    }
    for(int i=n-1;i>=0;i--) cout<<ans[i]<<endl;
    return 0;
}
