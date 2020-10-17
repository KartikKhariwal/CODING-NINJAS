#include<iostream>
using namespace std;

int p(int x,int n){
  if(n==0)return 1;
  if(n==1)return x;
  else if(n%2)return x*p(x,(n-1)/2)*p(x,(n-1)/2);
  else return p(x,n/2)*p(x,n/2);
  return 1;
}

int main() {
	// Write your code here
  int n;
  cin>>n;
  int x;
  cin>>x;
  cout<<p(n,x);	
}
