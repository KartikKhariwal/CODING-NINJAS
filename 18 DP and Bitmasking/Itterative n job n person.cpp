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
    int n;//no of jobs
    cin>>n;
    int **cost =new int*[n];
    for(int i=0;i<n;i++){
      cost[i]=new int[n];
      for(int j=0;j<n;j++){
        //for entering jobwise cost of each employee
        cin>>cost[i][j];
      }
    }
    vector<int> dp((1<<n)-1,INT_MAX);//for saving repeating ans
    dp[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int mask=q.front();q.pop();
        for(int i=0;i<n;i++){
          int person=__builtin_popcount(mask);  //mno of set bits is no of jobs alloted
          if(!(mask&(1<<i))){
            int temp=mask|(1<<i);
            q.push(temp);
            dp[temp]=min(dp[temp],dp[mask]+cost[person][i]);
          }
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}
