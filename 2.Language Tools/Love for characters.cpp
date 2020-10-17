#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    string s;cin>>s;
    int v[3]={0};
	for(auto x:s){
      if(x=='a')v[0]++;
      else if(x=='s')v[1]++;
      else if(x=='p')v[2]++;
    }	
    cout<<v[0]<<" "<<v[1]<<" "<<v[2];
  return 0;
}
