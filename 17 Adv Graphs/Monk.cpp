#include<bits/stdc++.h>
using namespace std;


int main()
{       std::ios::sync_with_stdio(false);
	//code
    int t;;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > edges(n+1);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
    vector<bool> visited(n+1,0);
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();   
        if(cur==n){
            break;
        }
        visited[cur]=1;
        for(int i =0;i<edges[cur].size();i++){
            int adj=edges[cur][i];
            if(!visited[adj]){
                    dist[adj]=min(dist[cur]+1,dist[adj]);
                    q.push(adj);
            }
        }
    }
    cout<<dist[n]<<endl;
}
	return 0;
}
