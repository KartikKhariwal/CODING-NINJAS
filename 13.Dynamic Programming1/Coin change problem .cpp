
#include<vector>

int count(int *coins,int m,int n,vector<vector<int> > &output){
    if(n==0)return 1;
    if(n<0)return 0;
    if(m==0)return 0;
    if(output[n][m]!=-1)return output[n][m];
    
    int first=count(coins,m,n-coins[0],output);
    int second=count(coins+1,m-1,n,output);
    output[n][m]=first+second;
    return output[n][m];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   // */
    // int **output=new int *[value+1];
    // for(int i=0;i<value+1;i++){
    //     output[i]=new int[numDenominations+1];
    //     for(int j=0;j<numDenominations+1;j++){
    //         output[i][j]=-1;
    //     }
    // }
    int n=value;
    int m=numDenominations;
    vector< vector< int> > output(n+1,vector<int>(m+1,-1));
         return count(denominations,numDenominations,value,output);

}
