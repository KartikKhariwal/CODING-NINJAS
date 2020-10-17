
#include<iostream>
using namespace std;
#define N 1000001
#define int long long


int* sieve(){
    int* primefactcount=new int[N];
    for(int i=0;i<N;i++){
        primefactcount[i]=0;
    }
    for(int i=2;i<N;i++){
        if(!primefactcount[i]){
            for(int j=i;j<N;j+=i){
                primefactcount[j]++;
            }
        }
    }
    return primefactcount;
}



int32_t main(){
	// Write your code here
   std::ios::sync_with_stdio(false);

    int *primefactcount=sieve();
    int **ans=new int*[1000001];
    for(int i=0;i<N;i++){
        ans[i]=new int[11];
        for(int j=0;j<11;j++){
            ans[i][j]=0;
        }
        
        if(i&&primefactcount[i]<=10)
            ans[i][primefactcount[i]]++;
    }
    
    for(int i=2;i<N;i++){
        for(int j=0;j<11;j++){
            ans[i][j]+=ans[i-1][j];
        }
        
    }

    
    
    int T;
    cin>>T;
    while(T--){
        int a,b,n;
        cin>>a>>b>>n;
      
        cout<<ans[b][n]-ans[a-1][n]<<endl;;
    }
    
	return 0;
}