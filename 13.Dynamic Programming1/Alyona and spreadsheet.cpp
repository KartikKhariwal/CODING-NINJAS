#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m;
    vector< vector<int> > v(n,vector<int>(m)),dp(n,vector<int>(m,0));//this dp stores consecutive increasing seq indexes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int j=0;j<m;j++){
        dp[0][j]=0;
        for(int i=1;i<n;i++){
            if(v[i][j]>=v[i-1][j])dp[i][j]=dp[i-1][j];
            else dp[i][j]=i;
        }
    }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
    
    //dp array for method 2
    int *dp1=new int [n];// this array stores min index from which consecutive in any column till ith row
    for(int i=0;i<n;i++){
        dp1[i]=i;
        for(int j=0;j<m;j++){
            dp1[i]=min(dp1[i],dp[i][j]);
        }
    }
    
    
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        if(dp1[b-1]<=a-1)cout<<"Yes\n";
        else cout<<"No\n";
        //method 1 with o(n) complexity
//         for(int i=0;i<m;i++){
//             if(dp[a-1][i]==dp[b-1][i]){
//                 cout<<"Yes\n";
//                 break;
//             }
//             else if(i==m-1){
//                 cout<<"No\n";
//             }
//         }
     
        //method 2
    }
    return 0;
}
