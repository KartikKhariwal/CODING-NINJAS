#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

pair<lint,lint> solve(const vector<lint> &v,int n,lint a){
  
  int start=0;int end=n-1;
  while(start<=end){
	  int mid=(end-start)/2+start;
	  if(v[mid]<=a&&v[mid+1]>a){
        return {mid+1,a-v[mid]};
      }
      else if(v[mid]>a){
        end=mid-1;
      }
    else{
      start=mid+1;
    }
  }
  return {0,a};
  
  
  
  
}


int main()
{  
  int n;cin>>n;
  vector<lint> v(n+1,0);
  for(int i=0;i<n;i++)cin>>v[i];
  v[n]=INT_MAX;
  for(int i=1;i<n;i++)v[i]+=v[i-1];
  int q;cin>>q;
  while(q--){
    lint a;
    cin>>a;
    pair<lint,lint> p=solve(v,n,a);
    cout<<p.first<<" "<<p.second<<endl;
  }
  
	return 0;
}
