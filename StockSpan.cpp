#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct twin{
     int a;
     int b;
};
int main()
{
     vector<int> que{100,80,60,70,60,75,85};
     int n=7;
     vector<int> ans;
     stack<twin> st;
     for(int i=0;i<n;i++)
     {
          while(st.size()!=0)
          {
               if(st.top().a > que[i])
               {
                    ans.push_back(i - st.top().b);
                    break;
               }
               else st.pop();
          }
          if(st.size()==0) ans.push_back(1);
          twin temp;
          temp.a = que[i];
          temp.b = i;
          st.push(temp);
     }
     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	return 0;
}
