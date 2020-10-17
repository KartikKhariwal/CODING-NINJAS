#define X (1000000007)

int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int *dp=new int[n+1]();//dp[i] strore no of bst for i nodes
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=((dp[i])%X+(((dp[j-1])%X)*(dp[i-j])%X)%X)%X;
        }
    }
    return dp[n];

}


