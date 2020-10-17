#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin>>t;
  	while(t--){
      long long val;
      cin>>val;
      int sum=0;
      while(val){
        sum+=val%10;
        val=val/10;
      }
      cout<<sum<<endl;
    }
}