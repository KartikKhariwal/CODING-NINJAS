#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node1{
    int A,B,C;
};

vector<node1> v(1000000),tree(4000000);

node1 getquery(int start,int end,int node,int left,int right){

    if(start>right||end<left||start>end)
    {   node1 temp;
        temp.A=INT_MIN;
        temp.B=INT_MAX;
        temp.C=INT_MAX;
        return temp;
    }

    //compl overlap
    if(start>=left&&end<=right){
        return tree[node];
    }

    //partial
    int mid=((start+end)>>1);
    node1 x=getquery(start,mid,node*2,left,right);
    node1 y=getquery(mid+1,end,node*2+1,left,right);

      if(x.A!=y.A){
        return ((x.A>y.A)?x:y);
    }
    else {
        if(x.B!=y.B){
            return ((x.B<y.B)?x:y);
        }
         else return ((x.C<y.C)?x:y);;
     }
}


void buildtree(int start,int end,int node){
    if(start==end){
        tree[node]=v[start];
        return ;
    }
    int mid=(start+end)/2;
    buildtree(start,mid,node*2);
    buildtree(mid+1,end,node*2+1);

    node1 x=tree[node*2],y=tree[node*2+1];
    
    if(x.A!=y.A){
        tree[node]=((x.A>y.A)?x:y);
    }
    else {
        if(x.B!=y.B){
            tree[node]=((x.B<y.B)?x:y);
        }
        else tree[node]=((x.C<y.C)?x:y);
    }
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    // #endif

    // Write your code here
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>v[i].A;
        v[i].C=i+1;
    }
    
    for(int i=0;i<n;i++){
        cin>>v[i].B;
    }
    buildtree(0,n-1,1);
    
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<getquery(0,n-1,1,a-1,b-1).C<<endl;
    }
}