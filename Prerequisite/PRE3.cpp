#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n;
    lint sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            lint x;
            cin>>x;
            if(i==0||j==0||i==n-1||j==n-1||i==j||j==n-1-i){
                sum += x;
            }
        }
    }
    cout<<sum;
	return 0;
}
