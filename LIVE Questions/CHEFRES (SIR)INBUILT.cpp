#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define input(v,n) for(lint i=0;i<n;i++)cin>>v[i];
#define output(v,n) for(lint i=0;i<n;i++)cout<<v[i]<<" ";

int main(){
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    lint t;
    cin>>t;
    while(t--){
    lint n,m;cin>>n>>m;
    vector<pair<lint,lint>> v(n);
    for(lint i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    while(m--){
    	lint a;
    	cin>>a;
    	if(a<=v[0].first){
    		cout<<v[0].first-a<<endl;
    	}else if(a>=v[n-1].second){
    		cout<<-1<<endl;
    	}
    	else{
    		int pos=lower_bound(v.begin(),v.end(),make_pair(a,0ll))-v.begin();
    		if(v[pos-1].second>a)cout<<0<<endl;
    		else cout<<v[pos].first-a<<endl;
    	}
    }
    }
    return 0;
}