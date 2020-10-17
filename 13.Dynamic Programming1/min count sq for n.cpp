
int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long *dp=new long[n+1];
//dp[i] gives min no of sq for num i
    for(int i=0;i<=n;i++){
        dp[i]=i;
    }
    for(int i=4;i<n+1;i++){
        for(int j=1;j<=i/2;j++){
            if(j*j<=i)
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    int ans=dp[n];
    delete []dp;
    return ans;
    
}