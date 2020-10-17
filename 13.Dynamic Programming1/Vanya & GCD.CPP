#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
#define int long long

// int gcd(int a, int b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b % a, a); 
// } 
 

int32_t main()
{
    
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<long> > dp(n,vector<long>(101,0));
    for(int i=0;i<n;++i){
        cin>>v[i];
        dp[i][v[i]]=1;
    }
    for(int i=1;i<n;i++){ 
        for(int j=0;j<i;j++){
            if(v[i]>v[j]){
                for(int k=1;k<=100;k++){
                    dp[i][__gcd(k,v[i])]+=dp[j][k];
                }
            }
        }
    }
    long ans=0;
    for(int i=0;i<n;i++){
        ans+=dp[i][1];
    }
    cout<<ans%(1000000007);
    return 0;
}
