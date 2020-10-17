#include<bits/stdc++.h>
typedef long long lint;
using namespace std;


bool checkplaced(const vector<lint> &v,lint n,lint c,lint mid){
  lint placed =1,last=0;
   for(int i=1;i<n;i++){
      if(v[i]-v[last]>=mid){placed++;;last=i;}
       if(placed==c)return 1;

    }
  return 0;
}


int main() {

  int t;
  cin>>t;
  while(t--){
    int n,c;
    cin>>n>>c;
    vector<lint> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    lint min=0,ans=-1;lint max=v[n-1]-v[0];
  while(max>=min){
    lint mid=(max-min)/2+min;
    
    if(checkplaced(v,n,c,mid)){
      ans=mid;
      min=mid+1;
    }else{
      max=mid-1;
    }
  }
    cout<<ans<<endl;
  }
  return 0;
}