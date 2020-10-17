#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,vector<bool> &visited,int i,stack<int> &s){
    visited[i]=1;
    for(int j=0;j<edges[i].size();j++){
        int adj=edges[i][j];
        if(!visited[adj]){
            dfs(edges,visited,adj,s);
        }
    }
    s.push(i);
}

void dfs2(vector<int>* edges,vector<bool> &visited,int color,int i,vector<int> &SCC ,vector<int> &components){
    SCC[i]=color;
    visited[i]=1;
    components.push_back(i);
     for(int j=0;j<edges[i].size();j++){
        int adj=edges[i][j];
        if(!visited[adj]){
            dfs2(edges,visited,color,adj,SCC,components);
        }
    }  
}


int main()
{
	//code
   
    while(1){
        long long n,m;
        cin>>n;
        if(n==0)break;
        cin>>m;
        vector<int>* edges=new vector<int>[n+1];
        vector<int>* edgesT=new vector<int>[n+1];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edgesT[y].push_back(x);
        }
        stack<int> s;
        vector<bool> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(edges,visited,i,s);
            }
        }
        for(int i=1;i<=n;i++){
            visited[i]=0;
        }
        vector<int> SCC(n+1,-1);
        vector<vector<int> > components;
        while(!s.empty()){    
         int i=s.top();
            if(!visited[i]){
                vector<int> component;
                dfs2(edgesT,visited,i,i,SCC,component);
                components.push_back(component);
            }
         s.pop();
        }
        // for(int i=1;i<=n;i++)cout<<SCC[i]<<" ";cout<<endl;
        vector<int> sol;
        for(auto x:components){
            int flag=1;
            // cout<<x.size()<<" ";
            for(int i=0;i<x.size();i++){
                for(int j=0;j<edges[x[i]].size();j++){
                    if(SCC[x[i]]!=SCC[edges[x[i]][j]]){
                        flag=0;break;
                    }
                }
                if(flag==0)break;
            }
            if(flag){
                for(int i=0;i<x.size();i++)sol.push_back(x[i]);
            }
        }
        sort(sol.begin(),sol.end());
        for(auto x:sol)cout<<x<<" ";
        cout<<endl;
        
        
        
        // for(int i=1;i<=n;i++){
        //     bool flag=1;
        //     for(int j=0;j<edges[i].size();j++){
        //         if(SCC[i]!=SCC[edges[i][j]]){
        //             flag=0;break;
        //         }
        //     }
        //     if(flag)cout<<i<<" ";
        // }        
        // cout<<endl;
    }
	return 0;
}
x