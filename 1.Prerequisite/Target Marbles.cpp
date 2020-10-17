#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int i, n ,target;
    cin>>n >> target;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
     for( i=0;i<n;i++){
         int sum=0;
        for(int j=i;j<n&&sum<target;j++){
            sum+=arr[j];
            if(sum==target){
                 cout<<"true\n";
             for(int k=i;target!=0;k++){
                cout<<arr[k]<<" ";
                  target-=arr[k];
                }
                return 0;
            }
        }
    }

        cout<<"false";

    
    
	return 0;
}
