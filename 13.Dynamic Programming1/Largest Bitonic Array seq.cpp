 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	int **dp=new int*[n];
	//dp[i][0] represent largest inc array till ith index
	//dp[i][1] represent largest dec array till ith index
        for(int i=0;i<n;i++){
            dp[i]=new int[2];
            dp[i][0]=1;dp[i][1]=1;
        }
        for(int i=1;i<n;i++){
            int x=1;
            for(int j=0;j<i;j++){
                if(input[j]<input[i]&&dp[j][0]+1>x){
                    x=1+dp[j][0];
                }
            }
            dp[i][0]=x;
        }
        
        for(int i=n-2;i>=0;i--){
            int x=1;
            for(int j=i+1;j<n;j++){
                if(input[j]<input[i]&&dp[j][1]+1>x){
                    x=1+dp[j][1];
                }
            }
            dp[i][1]=x;
        }
        int ma=0;
        for(int i=0;i<n;i++){
  //          cout<<dp[i][0]<<" "<<dp[i][1]<<endl; 
            ma=max(ma,dp[i][0]+dp[i][1]);
        }
        return ma-1;
     	
     	
 	}

