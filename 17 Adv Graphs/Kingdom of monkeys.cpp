
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,bool> visited;
unordered_map<int,int> parent;
unordered_map<int,long long>  ans;

void dfs(vector<int> *edges ,int node,int setparent){
    visited[node]=1;
    parent[node]=setparent;
    for(auto x:edges[node]){
        if(!visited[x]){
            dfs(edges,x,setparent);
        }
    }
}

int main()
{       std::ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        long n,m;
        cin>>n>>m;
        vector<int> edges[n+1];;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(edges,i,i);
            }
        }
        
        long long sol=INT_MIN;
        for(int i=1;i<=n;i++){
            // cout<<parent[i]<<" ";
            int x;
            cin>>x;
            ans[parent[i]]+=x;
            sol=max(ans[parent[i]],sol);
        }
        
        cout<<""<<sol<<endl;
        parent.clear();
        visited.clear();
        ans.clear();
    }
	return 0;
}
