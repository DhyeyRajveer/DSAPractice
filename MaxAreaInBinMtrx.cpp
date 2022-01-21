#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> makeHisto(vector<vector<int>> v, int rs, int cls)
{
     vector<int> histo;
     for(int j=0;j<cls;j++)
     {
          int height = 0;
          int k = rs-1;
          while(k!=-1 && v[k][j]!=0)
          {
               height++;
               k--;
          }
          histo.push_back(height);
     }
     cout<<"HISTO"<<endl;
     for(int i=0;i<cls;i++) cout<<histo[i]<<" ";
     cout<<endl;
     return histo;
}

vector<int> NSL(vector<int> v)
{
     vector<int> ans;
     int n = v.size();
     stack<pair<int,int>> stk;
     for(int i=0;i<n;i++)
     {
          if(stk.size()==0) ans.push_back(-1);
          else
          {
               while(stk.size()!=0 && stk.top().first>=v[i]) stk.pop();
               if(stk.size()==0) ans.push_back(-1);
               else ans.push_back(stk.top().second);
          }
          pair<int,int> temp{.first = v[i], .second = i};
          stk.push(temp);
     }
     /*cout<<"NSL"<<endl;
     for(int i=0;i<v.size();i++) cout<<ans[i]<<" ";
     cout<<endl;*/
     return ans;
}

vector<int> NSR(vector<int> v)
{
     int n = v.size();
     stack<pair<int,int>> stk;
     vector<int> ans;
     for(int i=n-1;i>=0;i--)
     {
          if(stk.size()==0) ans.push_back(n);
          else
          {
               while(stk.size()!=0 && stk.top().first>=v[i]) stk.pop();
               if(stk.size()==0) ans.push_back(n);
               else ans.push_back(stk.top().second);
          }
          pair <int,int> temp{.first = v[i], .second = i};
          stk.push(temp);
     }
     for(int i=0;i<n/2;i++)
     {
          int temp = ans[i];
          ans[i] = ans[n-1-i];
          ans[n-1-i] = temp;
     }
     /*cout<<"NSR"<<endl;
     for(int i=0;i<v.size();i++) cout<<ans[i]<<" ";
     cout<<endl;*/
     return ans;
}

int MAH(vector<int> v)
{
     vector<int> nsl = NSL(v);
     vector<int> nsr = NSR(v);
     int n = v.size();
     vector<int> width;
     for(int i=0;i<n;i++) width.push_back(nsr[i]-nsl[i]-1);
     /*cout<<"WIDTH"<<endl;
     for(int i=0;i<v.size();i++) cout<<width[i]<<" ";
     cout<<endl;*/
     int maxArea = 0;
     for(int i=0;i<n;i++)
     {
          int temp = width[i]*v[i];
          if(temp>maxArea) maxArea = temp;
     }
     return maxArea;
}

int MaxAreaInBinMtrx(vector<vector<int>> v, int rs, int cls)
{
     int maxAreaOfRec = 0;
     for(int i=0;i<rs;i++)
     {
          vector<int> histo;
          histo = makeHisto(v, i+1, cls);
          int temp = MAH(histo);
          if(temp>maxAreaOfRec) maxAreaOfRec = temp;
     }
     return maxAreaOfRec;
}

int main()
{
     vector<vector<int>> v{
          {1,1,1},
          {1,1,1},
          {1,1,1},
          {1,1,1}
     };
     int cls = 3;
     int rs = 4;
     int ans = MaxAreaInBinMtrx(v, rs, cls);
     cout<<"Max Area is: "<<ans<<endl;
	return 0;
}
