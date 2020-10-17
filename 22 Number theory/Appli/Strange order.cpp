#include<bits/stdc++.h>
using namespace std;
#define N 2000001
#define int long

long* lpd=new long[2000001]();

void sieve(){
    for(int i=0;i<N;i++){
        lpd[i]=i;
    }
    
    for(int i=2;i*i<N;i++){
        if(lpd[i]==i){
            for(int j=i*i;j<N;j+=i){
                lpd[j]=i;
            }
        }
    }
    
}

int32_t main() {
    
    sieve();
    bool* marked=new bool[N]();
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        if(!marked[i]){
            vector<int> temp;
            int ld=lpd[i];
            int x=i;
            while(ld!=1){
                for(int j=i;j>=1;j=j-ld){
                    if(!marked[j]){
                        marked[j]=1;
                        temp.push_back(j);
                    }
                }
                while(x%ld==0){
                    x=x/ld;
                }
                ld=lpd[x];
            } 
            sort(temp.begin(),temp.end(),greater<int>());
            for(auto it:temp){
                cout<<it<<" ";
            }
                        
        }
        else continue;
    
    }
    cout<<1;
    
    

	// Write your code here
}