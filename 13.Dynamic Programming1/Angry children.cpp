#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<long> v(n),dp(n-k+1);//dp array stores uniqueness
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    
    // for(int i=0;i<n;i++)cout<<v[i]<<" ";
    // cout<<endl;
    
    
    dp[0]=0;long sub=v[0];
    for(int i=1;i<k;i++){
        dp[0]+=v[i]*i-sub;
        sub+=v[i];
    }
    
 //   cout<<dp[0]<<" "<<sub<<endl;
    
    
    long maxi=dp[0];
    for(int i=1;i<n-k+1;i++){
        dp[i]=dp[i-1];
        dp[i]=dp[i]-(sub-k*v[i-1])+(k-1)*v[k+i-1]-(sub-v[i-1]);
        sub+=v[k+i-1]-v[i-1];
        maxi=min(maxi,dp[i]);    
    }
    cout<<maxi;
    return 0;
}
