#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>v1,pair<int,int> v2)
{
  if(v1.first==v2.first)
    return v1.second<v2.second;
  else return v1.first>v2.first;
  
}
int main()
{	int n,b,c,d;
    cin>>n;
 	unordered_map<int,string> mp;
 	string a;
 	vector<pair<int,int> > v(n); 
 	for(int i=0;i<n;i++){
      cin>>a;
      cin>>b>>c>>d;
      v.push_back({b+c+d,i+1});
      mp[i+1]=a;
    }
    sort(v.begin(),v.end(),compare);
 	for(int i=0;i<n;i++){
      cout<<i+1<<" "<<mp[v[i].second]<<endl;
    }
    
	return 0;
}
