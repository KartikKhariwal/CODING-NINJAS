#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n;
    cin>>n;
    lint even=0,odd=0;
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      if(i%2==0&&x%2==0){
        even+=x;
      }
      else if(i%2==1&&x%2==1){
        odd+=x;
      }
    }
   cout<<even<< " " << odd;
	return 0;
}
