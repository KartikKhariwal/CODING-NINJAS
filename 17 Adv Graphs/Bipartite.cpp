#include<bits/stdc++.h>
#define int  long long
using namespace std;
#define M 1000000007
//for connected graph 
\\ if graph is not connected run a loop for all non visited nodes
bool bipartite(vector<vector<int>> &edges,int n){
    if(n==0)return true;
    unordered_set<int> sets[2];
    queue<int> pending;
    sets[0].insert(0);
    pending.push(0);
    while(!pending.empty()){
        int cur=pending.front();
        pending.pop();
        int curset= sets[0].count(cur)>0?0:1;
        for(int i=0;i<edges[cur].size();i++){
            int neighbor = edges[cur][i];
            if(sets[0].count(neighbor)==0&&sets[1].count(neighbor)==0){
                sets[(curset+1)%2].insert(neighbor);
                pending.push(neighbor);
            }
            else if(sets[curset].count(neighbor)>0){
                return false;
            }
        }
    }
    return true;
}

int32_t main()
{  
    std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    while(1){
        int n,m;
        cin>>n;
        if(n==0)break;
        cin>>m;
        vector<vector<int> > edges(n);
        for(int i=0;i<m;i++){
            int a,b;//0 indexed i.e [0,..,n-1]
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
         
      bool ans = bipartite(edges, n);
      if (ans) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
return 0;
}