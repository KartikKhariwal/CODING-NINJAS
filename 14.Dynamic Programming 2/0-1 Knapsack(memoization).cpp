#include<bits/stdc++.h>
using namespace std;

int knapsacks(int* weights, int* values, int n, int maxWeight,int**dp){
    if(n==0||maxWeight==0){
        return 0;
    }
    if(dp[n][maxWeight]!=-1)return dp[n][maxWeight];
    long long ans1=-INT_MIN,ans2;
    if(weights[0]<=maxWeight){
        ans1=values[0]+knapsacks(weights+1,values+1,n-1,maxWeight-weights[0],dp);
    }
    ans2=knapsacks(weights+1,values+1,n-1,maxWeight,dp);
    dp[n][maxWeight]=max(ans1,ans2);
    return max(ans1,ans2);
}



int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */

   int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j]=-1;
        }
    }
   return knapsacks(weights,values,n,maxWeight,dp);

}
