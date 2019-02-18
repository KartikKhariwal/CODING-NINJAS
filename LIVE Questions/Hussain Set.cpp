#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n,m;
    cin>>n>>m;
    lint v[n];
  	for(int i=0;i<n;i++)cin>>v[i];
  	sort(v,v+n);
  	queue<lint> q;
    int last=n-1;
  	int counter=0;;
  	for(int i=0;i<m;i++){
  	    int t;
  	    cin>>t;
  	    lint ans;
  	    while(counter!=t){
  	        counter++;
            if(last>=0&&(q.empty()||q.front()<=v[last])){
                ans=v[last];
                last--;
            }
            else {
                    ans=q.front();
                    q.pop();
                }
            q.push(ans/2);
            }
            cout<<ans<<endl;
  	    }
  	
  	return 0;
}
