//DP with Bitmasking
//min cost n jobs n persons


#include<bits/stdc++.h>
using namespace std;

int mincost(int cost[4][4],int n,int person ,int mask,vector<int> &dp){
  if(person>=n)return 0;
  if(dp[mask]!=-1)return dp[mask];
  int ans=INT_MAX;
  for(int i=0;i<n;i++){
    if(!((1<<i)&mask)){
         ans=min(ans,mincost(cost,n,(person+1)%(n+1),(mask|(1<<i)),dp)+cost[person][i]);
    }
  }
  dp[mask]=ans;
  return ans;
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    int n=4;//no of jobs
    int cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};//persons vs job ->cost
    vector<int> dp((1<<n)-1,-1);//for saving repeating ans

    //recusrion bitmasking 
    cout<<mincost(cost,4,0,0,dp);
    return 0;
}
