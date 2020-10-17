/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don�t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else return 0;
    }
    else{
          int x=0;
          int newop1[10000][50],newop[10000][50];
        //  if(input[0]<=k){
                 x=subsetSumToK(input+1,n-1,newop,k-input[0]);
        //  }
            
            int y=subsetSumToK(input+1,n-1,newop1,k);
           for(int i=0;i<x;i++){
                for(int j=1;j<=newop[i][0];j++){
                output[i][j+1]=newop[i][j];
            }
            output[i][0]=newop[i][0]+1;
            output[i][1]=input[0];
           
        }
        for(int i=0;i<y;i++){
            for(int j=0;j<=newop1[i][0];j++){
                output[x+i][j]=newop1[i][j];
            }
        }
        return x+y;         
    }
}
