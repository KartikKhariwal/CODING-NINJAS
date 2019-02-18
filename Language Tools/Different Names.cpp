#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string,int> mp;
    string s;bool ans=0;
	while(cin>>s){
     mp[s]++;
      if(mp[s]>1)ans=1;
	}	    
  if(!ans)cout<<-1;
  else{
    for(auto x:mp){
      if(x.second>1){
        cout<<x.first<<" "<<x.second<<endl;
      }
    }
  }
	return 0;
}
