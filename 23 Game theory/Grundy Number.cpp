#include<bits/stdc++.h>
using namespace std;

long long mex(long long a,long long b,long long c){
    long long j=max(a,max(b,c))+1;
    for(long long i=0;i<=j;i++){
        if(i!=a&&i!=b&&i!=c){
            return i;
        }
    }
}

long long grundy(int n){
    if(n==0){
        return 0;
    }
    else{
        return mex(grundy(n/2),grundy(n/3),grundy(n/6));
    }
}


int main() {
    
    int n;
    cin>>n;
    cout<<grundy(n);
    
	// Write your code here
}