#include<bits/stdc++.h>
int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int *dp=new int[1001]();
	//dp[i] stores max so far
    dp[0]=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[A[i]]++;
    }
    if(mp[1]){
        dp[1]=mp[1];
    }
    else dp[1]=0;
    for(int i=2;i<=1000;i++){
        dp[i]=max(dp[i-1],mp[i]*i+dp[i-2]);
    }
    int ans=dp[1000];
    delete []dp;
    return ans;

}