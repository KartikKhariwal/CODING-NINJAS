
// #define max(a,b) ((a>b)?(a):(b))
#include<bits/stdc++.h>
using namespace std;
//o(n^3) soln
// bool find(int *v,int x,int n){
//     int maxans=0,curans=0;
//     if(maxans>=x)return 1;
//     for(int i=0;i<n;i++){
//         if(v[i]==0)curans++;
//         else {
//             maxans=max(maxans,curans);
//             if(maxans>=x)return 1;
//             curans=0;
//         }
//     }
//     if(maxans>=x)return 1;
//     else return 0;
// }

// int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
//     /* Don't write main().
//      *  Don't read input, it is passed as function argument.
//      *  Return output and don't print it.
//      *  Taking input and printing output is handled automatically.
//      */
//     int ans=0;
//     for(int i=0;i<col;i++){
//        int* sum=new int[row]();
//         for(int j=i;j<col;j++){
//             for(int k=0;k<row;k++){
//                 sum[k]+=arr[k][j];
//             }
//             if(find(sum,j-i+1,row)){
//                 ans=max(ans,j-i+1);
//             } 
//         }
//     }
//     return ans;
    
// }


//o(n^2)
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    vector< vector<int> > dp(row,vector<int>(col,0));//will store sq matrix till ij so far
 
    for(int i=0;i<row;i++){
        dp[i][0]=(arr[i][0]==0)?1:0;
    }
    for(int i=0;i<col;i++){
        dp[0][i]=(arr[0][i]==0)?1:0;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j])dp[i][j]=0;
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    int maxi=-INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
}