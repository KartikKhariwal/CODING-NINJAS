#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        int i;
        for( i=0;i<n-1;++i){  
        if(v[i]==i)continue;
        else if(v[i]==i+1&&v[i+1]==i){
            i++;
        }
        else{
          break;
        }
        
        }
    if(i>=n-1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
	return 0;
}
