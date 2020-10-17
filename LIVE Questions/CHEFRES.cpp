#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define input(v,n) for(lint i=0;i<n;i++)cin>>v[i];
#define output(v,n) for(lint i=0;i<n;i++)cout<<v[i]<<" ";


lint ans(const vector<pair<lint,lint> > &v,lint a,lint n){

		int start=0,end=n-1;
		while(start<=end){
			int mid=(start + end)/2;
			if(v[mid].first<a){
				start=mid+1;
			}
			else if(v[mid].first>a){
				if(v[mid-1].first<a){
					if(v[mid-1].second>a){
						return 0;
					}
					else return v[mid].first-a;
				}
				else end=mid-1;
			}
			else return 0;
		}
		return 0;
}


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
    		cout<<ans(v,a,n)<<endl;
    	}
    }
    }
    return 0;
}