
long long ans(int like[][MAXN],int N,int person,int mask,vector<long long> &dp){
    // cout<<mask<<" "<<dp[mask]<<endl;
    
    if(dp[mask]!=-1){
        return dp[mask];
    }
    if(person>N)return 0;
   
    long long temp=0;
    for(int i=0;i<N;i++){
        if((!(mask&(1<<i)))&&like[person][i]==1){
             temp+=ans(like,N,person+1,(mask|(1<<i)),dp);           
        }
    }
    dp[mask]=temp;
    return dp[mask];
    
}

long long solve(int like[][MAXN],int N)
{    
	// Write your code here.
    vector<long long> dp((1<<N),-1);
    dp[(1<<N)-1]=1;
    long long temp= ans(like,N,0,0,dp);
    return dp[0];
    
}