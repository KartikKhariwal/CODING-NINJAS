#include<bits/stdc++.h>
using namespace std;
int main() {
 int n;cin>>n;
int *a=new int[n];
int *b=new int[n];
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
   for(int i=0;i<n;i++){
   cin>>b[i];
 }
sort(a,a+n);
sort(b,b+n);
int ans=0,count=0;
for(int i=0,j=0;i<n&&j<n;){
  if(a[i]<b[j]){
    count++;i++;
    if(count>ans)ans=count;
  }
  else{
    count--;j++;
  }
  
}  
  cout<<ans;
  // Write your code here
}