#define max(a,b) ((a>b)?(a):(b))
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    long *dp=new long[n]();
//dp[i] gives max loot till ith house so far
    dp[0]=arr[0];
    if(n>1)dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        //printf("%d\n",dp[i]);
    }
    
    
    return dp[n-1];
}
