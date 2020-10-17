#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n,m;
    cin>>n>>m;
    vector<long> v(n+2,0);
    for(int i=0;i<m;i++){
        long a,b;
        cin>>a>>b;
        v[a]+=1;v[b+1]-=1;// to fill in O(n) time 
    }
    long cur=0;
    
    //filling lr in O(n) time
    for(int i=1;i<=n;i++){
        cur+=v[i];
        v[i]=cur;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    long q;
    cin>>q;
    long dp[n+1]={0};
    //    //converting from foxes ->coins to coins->boxes

    for(int i=n;i>=1;i--){
        dp[v[i]]++;
    }
    // for(int i=0;i<=m;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    
    //applying dp for atleast
    for(int i=m-1;i>=0;i--){
        dp[i]=(dp[i]+dp[i+1]);
    }
    
    //answering queries
    while(q--){
        int x;
        cin>>x;
       cout<<dp[x]<<endl;
    }
    return 0;
}
