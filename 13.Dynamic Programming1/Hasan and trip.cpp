#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector < pair <double,double> > v(n);
    vector<double> dp(n,-INT_MAX),f(n);
//dp[i] represents max happiness level so far of ith city
    for(int i=0;i<n;i++){
        double a,b;
        cin>>a>>b>>f[i];
    v[i]={a,b};
    }
    dp[0]=f[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],dp[j]+f[i]-sqrt((v[i].second-v[j].second)*(v[i].second-v[j].second)+(v[i].first-v[j].first)*(v[i].first-v[j].first)));
        }
    }
//if(dp[n-1]>=0)
    cout<<std::fixed<<setprecision(6)<<(dp[n-1]);
    // else {
    //     cout<<ceil(dp[n-1])<<"."<<setprecision(6)<<-1*(dp[n-1]-ceil(dp[n-1]))*1000000;
    // }
}
