#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
     vector<int> q{6,2,5,4,5,1,6};
     stack<pair<int,int>> sL;
     stack<pair<int,int>> sR;
     int maxArea=0, n = q.size();
     vector<int> nsl;
     vector<int> nsr;
     // Smallest bar to the left
     for(int i=0;i<n;i++)
     {
          if(sL.size()==0) nsl.push_back(1);
          else
          {
               while(sL.size()!=0 && sL.top().first>=q[i]) sL.pop();
               if(sL.size()==0) nsl.push_back(i+1);
               else nsl.push_back(i-sL.top().second);
          }
          pair<int,int> temp{.first = q[i], .second = i};
          sL.push(temp);
     }

     for(int i=n-1;i>=0;i--)
     {
          if(sR.size()==0) nsr.push_back(1);
          else
          {
               while(sR.size()!=0 && sR.top().first>=q[i]) sR.pop();
               if(sR.size()==0) nsr.push_back(n - i);
               else nsr.push_back(sR.top().second - i);
          }
          pair<int,int> temp{.first = q[i], .second = i};
          sR.push(temp);
     }
     //Reversing sR
     for(int i=0;i<n/2;i++)
     {
          int temp = nsr[i];
          nsr[i] = nsr[n-1-i];
          nsr[n-1-i] = temp;
     }

     maxArea = 0;
     for(int i=0;i<n;i++)
     {
          int height = q[i];
          int width = nsl[i]+nsr[i]-1;
          if(height*width>maxArea) maxArea = height*width;
     }
     cout<<"Maximum Area is: "<<maxArea<<endl;
	return 0;
}
