#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

long long merge(int* &v,int st,int mid,int end){
  
  
  int * op=new int[end-st+1];
  int i=st,k=0,j=mid;
  lint ans=0;
  for(;i<mid&&j<=end;){
    if(v[i]<v[j]){
      ans+=(end-j+1)*v[i];
      op[k++]=v[i++];
    }
    else {
      op[k++]=v[j++];
    }
  }
      while(j<=end){
         op[k++]=v[j++];
      }
      while(i<mid){
         op[k++]=v[i++];
      }

  for(int i=st,k=0;i<=end;i++){
    v[i]=op[k++];
  }
  return ans;
  
} 

long long murder(int *v,int st,int end){
  if(end-st<=0)return 0;
  int mid=(st+end)/2;
  long long left=murder(v,st,(st+end)/2);
  long long right =murder(v,(st+end)/2+1,end);
  long long ct=merge(v,st,mid+1,end);
    return ct+left+right;

}




long long solve(int A[], int n)
{
	// binary search mostly wha lgti h jhape particular items ki arrangement krni hoti h
     
 
  return murder(A,0,n-1);
 
}

int main() {

	// Write your code here
  int t;
  cin>>t;
  while(t--){
    int n;cin>>n;
    int *v=new int[n];
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<solve(v,n)<<endl;
  }
}