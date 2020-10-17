#include<bits/stdc++.h>
using namespace std;
#define int long long


vector<int> v(100005),tree(400005),two(100007);

void update(int start,int end,int pos,int node){
    
    if(start>end)return ;
    
    if(start==end){
        v[pos]=1;
        tree[node]=1;
        return ;
    }
    
    int mid=(start+end)/2;
    if(pos>mid){
        update(mid+1,end,pos,node*2+1);
    }
    else update(start,mid,pos,node*2);
    
    tree[node]=((tree[node*2+1]) + (two[end-mid]*(tree[node*2]))%3)%3;
    return ;
}

int getquery(int start,int end,int node,int left,int right){

    if(start>right||end<left||start>end) return 0;


    //compl overlap
    if(start>=left&&end<=right){
        return (tree[node]*two[right-end])%3;
    }

    //partial
    int mid=((start+end)/2);
    int x=getquery(start,mid,node*2,left,right);
    int y=getquery(mid+1,end,node*2+1,left,right);
    return (y + x)%3;
    
}


void buildtree(int start,int end,int node){
    if(start==end){
        tree[node]=v[start];
        return ;
    }
    
    int mid=(start+end)/2;
    buildtree(start,mid,node*2);
    buildtree(mid+1,end,node*2+1);
    tree[node]=((tree[node*2+1]) + (two[end-mid]*(tree[node*2]))%3)%3;
    return ;
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
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        v[i]=((s[i]=='1')?1:0);
    }
    two[0]=1;
    for(int i=1;i<=n;i++){
        two[i]=(two[i-1]*2)%3;
    }
    
    buildtree(0,n-1,1);
    // for(int i=1;i<10;i++)cout<<tree[i]<<" ";cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x){
            int pos;
            cin>>pos;
            if(v[pos]==0)update(0,n-1,pos,1);
        }
        else{
        int a,b;
        cin>>a>>b;
        cout<<getquery(0,n-1,1,a,b)<<endl;
        }
    }
}