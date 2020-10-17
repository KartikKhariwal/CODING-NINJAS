//Another method is finf connected components and then check at their indices if all elements are identical or not as together


#include<bits/stdc++.h>
using namespace std;
unordered_map<int,bool> visited;
unordered_map<int,int> parent;

void dfs(vector<int> *edges,int *P ,int node,int setparent){
    visited[node]=1;
    parent[P[node-1]]=setparent;
    for(auto x:edges[node]){
        if(!visited[x]){
            dfs(edges,P,x,setparent);
        }
    }
}

int main()
{
	// I am making parent of each connected component same an hence checking it later
    int t;
    cin>>t;
    while(t--){
        long n,m;
        cin>>n>>m;
        int * P=new int[n],*Q=new int[n];
        for(int i=0;i<n;i++){
            cin>>P[i];
        }
        for(int i=0;i<n;i++){
            cin>>Q[i];
        }
        vector<int> edges[n+1];;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(edges,P,i,i);
            }
        }
        
        for(int i=0;i<n;i++){
            if(parent[P[i]]==parent[Q[i]]){
                visited[0]=true;
                continue;
            }
            else {
                visited[0]=false;break;
            }
        }
        cout<<((visited[0])?"YES":"NO")<<endl;
        delete []P;
        delete []Q;
        parent.clear();
        visited.clear();
    }
	return 0;
}
