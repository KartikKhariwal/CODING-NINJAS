#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n,x,buy=101,sell=49,profit=0;
    cin>>n;
    cin>>x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x<buy){
            buy=x;
            sell=x;
        }
        else if(x>sell){
            sell=x;
        }
        
        profit=max(profit,sell-buy);
    }
    cout<<profit;
	return 0;
}
