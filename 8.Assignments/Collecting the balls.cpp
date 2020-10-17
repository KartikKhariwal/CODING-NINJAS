#include<bits/stdc++.h>
using namespace std;

long long solve(long long n,long long mid){
    long long sharma=0,vikas=0;
    long long temp=n;
    while(n!=0){
        sharma+=mid;
        n-=mid;
        if(n<0){
            sharma+=n;
            n=0;
        }
        vikas+=(n)/10;
        n-=n/10;
    }
    if(sharma>=(temp+1)/2){
        return 1;
    }
    else return -1;
    
    
}

int main()
{
    long long n;
    cin>>n;
    long long start=1,end=(n+1/2);
    while(start<end){
        long long mid=(end-start)/2+start;
        if(solve(n,mid)!=-1){
            end=mid;
        }
        else {
            start=mid+1;
        }
    }
    cout<<(start+end)/2;
    return 0;
	return 0;
}
