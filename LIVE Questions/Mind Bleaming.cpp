#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n;
    cin>>n;
    vector<lint> p(n),a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int lp=1;
    for(int i=0;i<n;i++){
        p[i]=lp;
        lp*=a[i];
    } 
    int rp=1;
    for(int i=n-1;i>=0;i--){
        p[i]*=rp;
        rp*=a[i];
    }  	
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    return 0;
}
