#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    map<lint,lint> mp;
    for(int i=0;i<n+m+k;i++){
        lint x;
        cin>>x;
        mp[x]++;
    }
    lint count =0;
    for(auto x:mp){
        if(x.second>=2)count++;
    }
    cout<<count<<endl;
     for(auto x:mp){
        if(x.second>=2)cout<<x.first<<endl;
    }
    return 0;
}
