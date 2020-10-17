#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector< vector<int> > dp(n,vector<int> (m,0)),input(n,vector<int> (m,0));
        //dp[i][j] represent min health from i j pt to reach n,m
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>input[i][j];
            }
        }
         dp[n-1][m-1]=input[n-1][m-1]>=1?1:1-input[n-1][m-1];
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=(dp[i+1][m-1]-input[i][m-1]>=1)?dp[i+1][m-1]-input[i][m-1]:1;
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=(dp[n-1][i+1]-input[n-1][i]>=1)?dp[n-1][i+1]-input[n-1][i]:1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=min((dp[i+1][j]-input[i][j]>=1)?dp[i+1][j]-input[i][j]:1,(dp[i][j+1]-input[i][j]>=1)?dp[i][j+1]-input[i][j]:1);
            }
        }
        cout<<dp[0][0]<<endl;
        
    }
}
