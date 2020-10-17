#include<bits/stdc++.h>
using namespace std;
int main() {
int time[2400]={0};
 int n;cin>>n;
int *a=new int[n];
int *b=new int[n];
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
   for(int i=0;i<n;i++){
   cin>>b[i];
 }
  for(int i=0;i<n;i++){
      for(int j=a[i];j<b[i];j++){
        time[j]++;
      }
 } 
  int ma=0;
 for(int j=0;j<2400;j++){
        ma=max(ma,time[j]);
      }
cout<<ma;	
  // Write your code here
}