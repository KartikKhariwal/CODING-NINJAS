#include<bits/stdc++.h>
using namespace std;
#define N 50000
#define M (1000000007)

bool* isprime =new bool[50001];

void sieve(){
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i<=N;i++){
        isprime[i]=true;
    }
    
    for(int i=2;i*i<=N;i++){
        if(isprime[i]){
            for(int j=i*i;j<=N;j+=i){
                isprime[j]=false;
            }
        }
    }
}

int main(){
	// Write your code here
    sieve();
    int T;
    cin>>T;
    while(T--){
        
        int n;
        cin>>n;
        long long fact=1;
        for(int i=2;i<=n;i++){
            if(isprime[i]){
                int count =0;
                for(int j=i;j<=n;j*=i){
                    
                    count+=n/j;     //bec there are n/p   times p in n
                    
                }
              fact=(fact* (count+1) )%M;   //no 0f div =(a+1)( b+1).... where a,b,.. are powers of prime

            }
        }
        cout<<fact<<endl;
        
    }
    
	return 0;
}