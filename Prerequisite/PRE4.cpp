#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     for(int i=0;i<n/2;i++){
        cout<< (arr[i]+arr[n-1-i])/10 <<" "<< (arr[i]+arr[n-1-i])%10 <<endl;
    }
    
	return 0;
}
