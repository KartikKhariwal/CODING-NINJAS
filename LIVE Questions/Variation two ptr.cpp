#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define input(v,n) for(lint i=0;i<n;i++)cin>>v[i];
#define output(v,n) for(lint i=0;i<n;i++)cout<<v[i]<<" ";
/*


*/
int main(){
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // while(t--){
    lint n,m;cin>>n>>m;
    vector<lint> v(n);
    for(lint i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int i=0,j=0,ans=0;
    while(j!=n){
    	if(i==j)j++;
    	else {
    		if(abs(v[i]-v[j])>=m){
    			ans+=n-j;
    			i++;
    		}else j++;
    	}
    }
    cout<<ans;

    return 0;
}