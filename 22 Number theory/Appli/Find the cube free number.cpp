#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int* cubefree=new int[N];

void cubicsieve(){
    for(int i=0;i<N;i++){
        cubefree[i]=1;
    }
    
    
    for(int i=2;i<=100;i++){
        int k=i*i*i;
        for(int j=1;j*k<N;j++){
             cubefree[j*k]=-1;
        }
    }
    for(int i=1,j=1;i<N;i++){
        if(cubefree[i]!=-1){
            cubefree[i]=j++;
        }
    }
    
}

int32_t main()
{   std::ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGEb
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    // #endif
    cubicsieve();
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        
        int n;
        cin>>n;
        cout<<"Case "<<i<<": ";
        if(cubefree[n]!=-1){
            cout<<cubefree[n]<<endl;
        }
        else{
            cout<<"Not Cube Free"<<endl;
        }
    }
  return 0;
}

