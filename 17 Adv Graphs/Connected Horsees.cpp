#include<bits/stdc++.h>
using namespace std;
long long fact[1000000];
int X[8]={-2,-2,-1,1,2,2,1,-1};
int Y[8]={-1,1,2,2,1,-1,-2,-2};
#define M 1000000007

void factcL(){
    fact[0]=1,fact[1]=1;
    for(int i=2;i<=1000000;i++){
        fact[i]=((fact[i-1]%M)*(i))%M;
    }
}

int dfs(int** edges,int i,int j,int n,int m){
    edges[i][j]=0;
    int subans=0;
    // cout<<i<<" "<<j<<endl;
    for(int x=0;x<8;x++){
        int newi=X[x]+i;
        int newj=Y[x]+j;
        if(newi>=1&&newi<=n&&newj>=1&&newj<=m&&edges[newi][newj]){
            subans+=dfs(edges,newi,newj,n,m);
        }
    }
    // cout<<subans<<endl;
    return subans+1;
}
    


int main()
{
	//code
    factcL();
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        long long ans=1;
        cin>>n>>m>>q;
        int **arr=new int*[n+1];
        for(int i=0;i<n+1;i++){
            arr[i]=new int[m+1]();
        }
        while(q--){
            int a,b;
            cin>>a>>b;
            arr[a][b]=1;
        }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++)
             if(arr[i][j]){
                 long long ct=dfs(arr,i,j,n,m);
                              ans=((ans%M)*fact[ct])%M;
             }
     }
        cout<<ans<<endl;
        
    }
    return 0;
}
