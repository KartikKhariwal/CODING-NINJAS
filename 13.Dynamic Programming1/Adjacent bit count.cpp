#include <bits/stdc++.h>
using namespace std;
#define X (1000000007)
#define MAX 1000

int solve(int n,int k,int start,int dp[][MAX][2]){
    
    if(n==1){
       if(k==0)return 1;
        else return 0;
    }
    if(dp[n][k][start]!=-1)return dp[n][k][start];
    
    if(k<0)return 0;
    long long ans=0;   
    if(start){
    ans=(solve(n-1,k-1,1,dp)%X+solve(n-1,k,0,dp)%X)%X;
    }else{
       ans=(solve(n-1,k,1,dp)%X+solve(n-1,k,0,dp)%X)%X;
    }
     dp[n][k][start]=ans;
        return ans;
}

int main()
{
    
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
     //   vector< vector<pair<int,int> > > dp(b+1,vector<pair<int,int> > (c+1,{-1,-1}));
        int dp[MAX][MAX][2]; 
        memset(dp, -1, sizeof(dp));
      cout<<a<<" "<<(solve(b,c,0,dp)*1ll+1ll*solve(b,c,1,dp))%X<<endl;
        
    }
    return 0;
}
