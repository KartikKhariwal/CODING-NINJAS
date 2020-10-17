#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<lint> v(n+m+k);
    for(int i=0;i<n+m+k;i++){
        cin>>v[i];
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=1,count =1;i<n+m+k;i++){
        if(v[i]==v[i-1])count++;
        else{
            if(count>=2){ans++;}
            count =1;
        }
    }
    cout<<ans<<endl;
      for(int i=1,count =1;i<n+m+k;i++){
        if(v[i]==v[i-1])count++;
        else{
            if(count>=2){cout<<v[i-1]<<endl;}
            count =1;
        }
    }
    return 0;
}
