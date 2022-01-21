#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> GR(vector<int> a, int n)
{
     int gl = 0;
     vector<int> ans;
     for(int i=n-1;i>=0;i--)
     {
          if(a[i]>gl) gl = a[i];
          ans.pb(gl);
     }
     for(int i=0;i<n/2;i++)
     {
          int temp = ans[n-1-i];
          ans[n-1-i] = ans[i];
          ans[i] = temp;
     }
     return ans;
}

vector<int> GL(vector<int> a, int n)
{
     int gr = 0;
     vector<int> ans;
     for(int i=0;i<n;i++)
     {
          if(a[i]>gr) gr = a[i];
          ans.pb(gr);
     }
     return ans;
}

int rainTrapped(vector<int> a)
{
     int area = 0, n = a.size();
     vector<int> gl = GL(a,n);
     vector<int> gr = GR(a,n);
     for(int i=0;i<n;i++)
     {
          int wa=min(gl[i], gr[i]); // Water above
          int rain = wa - a[i];
          area += rain;
     }
     return area;
}

int main()
{
     vector<int> bd{1,3,1,2,4,1,0,3,1,4,2,1,2,3};
     cout<<rainTrapped(bd)<<endl;
	return 0;
}
