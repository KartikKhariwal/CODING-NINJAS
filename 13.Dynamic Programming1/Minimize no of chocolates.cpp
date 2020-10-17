int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
    int *dp=new int [n]();
    dp[0]=1;
    
    //left optimization
    for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                dp[i]=dp[i-1]+1;
            }
            else dp[i]=1;
    }
    
    //rt optimization
    for(int i=n-1;i>0;i--){
            if(arr[i-1]>arr[i]&&dp[i-1]<=dp[i]){
                dp[i-1]=dp[i]+1;
            }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
       // printf("%d ",dp[i]);
        ans+=dp[i];
    }
    delete []dp;
    return ans;
}

