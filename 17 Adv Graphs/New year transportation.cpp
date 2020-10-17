#include<bits/stdc++.h>
using namespace std;
int main()
{
	//code
    long long n,t;
    cin>>n>>t;
   
    vector<long long > temp(n);
    for(int i=1;i<n;i++){
        cin>>temp[i];
    }
    for(int i=1;i<n;){
        i=i+temp[i];
        if(i==t){
            cout<<"YES";return 0;
        }
        else if(i>t)break;
    }
    cout<<"NO";
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std; 
// int x,n,t; vector<int> adj[300010]; 
// bool visited[300010]; 
// void dfs(int i) { visited[i]=true; 
//                  for (int j: adj[i]) 
//                  { if (!visited[j]) 
//                  { dfs(j); 
//                  } 
//         } 
// }
// int main() 
// { memset(visited,false,sizeof visited); 
//  cin>>n>>t; for (int i=1; i<n; i++)
//  { cin>>x; adj[i].push_back(x+i); }
//  dfs(1); if (visited[t]) cout<<"YES"<<endl; 
//  else cout<<"NO"<<endl; }
