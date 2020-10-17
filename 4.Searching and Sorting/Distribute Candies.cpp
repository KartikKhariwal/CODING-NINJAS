typedef long long lint;
#include<bits/stdc++.h>
using namespace std;


bool check(const vector<lint> &v,lint mid,int n,lint k){
  lint sum=0;
  if(mid==0)return 1;
  for(int i=0;i<n;i++){
    sum+=v[i]/mid;
    if(sum>=k)return 1;
  }
  return 0;
}


lint solve(const vector<lint> &v,int n,lint k){
  
  lint start=0,ans=0,end=*max_element(v.begin(),v.end());
  while(start<=end){
    lint mid=(end-start)/2+start;
    if(check(v,mid,n,k)){
      ans=mid;
      start=mid+1;
    }
    else{
      end=mid-1;
    }    
    
  }
  return ans;
  
}





int main() {

	// Write your code here
  int t;cin>>t;
  while(t--){
    int n;lint k;
    cin>>n>>k;
    vector<lint> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<solve(v,n,k)<<endl;
  }
  
}