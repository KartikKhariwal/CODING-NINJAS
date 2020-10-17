#include <bits/stdc++.h>
using namespace std;

long kadane(const vector<long> &v){
    
    int maxsum=-INT_MAX,cursum=0;
    for(int i=0;i<v.size();i++){
        cursum+=v[i];
        if(cursum>maxsum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
    }
    return maxsum;
}

int main()
{   
    int n,m;
    cin>>n>>m;
    vector< vector<long> > input(n,vector<long> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }
    
    // //O(n^4) soln
    //    vector< vector<long> > sum (n+1,vector<long> (m+1,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         for(int k=i;k<n;k++){
    //             for(int l=j;l<m;l++){
    //                 sum[i][j]+=input[k][l];
    //             }
    //         }
    //     }
    // }
    // long maxi=-INT_MAX;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         for(int k=i;k<n;k++){
    //             for(int l=j;l<m;l++){
    //                 maxi=max(maxi,sum[i][j]-sum[i][l+1]-sum[k+1][j]+sum[k+1][l+1]);
    //             }
    //         }
    //     }
    // }
    // cout<<maxi;
    
    
     //O(n^3) soln
    long maxi=-INT_MAX;
    for(int i=0;i<m;i++){
        vector<long> sum(n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                sum[k]+=input[k][j];
            }
            long maxsum=kadane(sum);
            maxi=max(maxi,maxsum);
        }
    }
    cout<<maxi;
    
    
   
    
    return 0;
}
