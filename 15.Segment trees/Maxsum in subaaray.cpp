#include<bits/stdc++.h>
using namespace std;
#define int long long
 
struct node{
    int maxsum;
    int sum;
    int prefix;//best prefix sum
    int suffix;//best suffix sum
};

node getquery(node *tree,int start,int end,int treenode,int left,int right){
    // cout<<start<<" "<<end<<endl;
    //completely outside
    if(start>right||end<left)return {INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    
    //completely inside
    if(start>=left &&end<=right){
        return tree[treenode];
    }
    
    //partial 
    int mid=(start+end)/2;
    node ans1=getquery(tree,start,mid,treenode*2,left,right);
    node ans2=getquery(tree,1+mid,end,treenode*2+1,left,right);
    int ans=max(ans1.maxsum,ans2.maxsum);
    ans=max(ans,ans1.suffix+ans2.prefix);
    return {ans,ans1.sum+ans2.sum,max(ans1.prefix,ans2.prefix+ans1.sum),max(ans2.sum+ans1.suffix,ans2.suffix)};
}

void buildtree(int *arr,node *tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode]={arr[start],arr[start],arr[start],arr[start]};
        return ;
    }
    
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,treenode*2);
    buildtree(arr,tree,mid+1,end,treenode*2+1);
    tree[treenode].sum=tree[treenode*2+1].sum+tree[treenode*2].sum;
    tree[treenode].maxsum=max(tree[treenode*2].maxsum,max(tree[treenode*2+1].maxsum,tree[treenode*2].suffix+tree[treenode*2+1].prefix));
    tree[treenode].prefix=max(tree[treenode*2].prefix,tree[treenode*2].sum+tree[treenode*2+1].prefix);
    tree[treenode].suffix=max(tree[treenode*2+1].suffix,tree[treenode*2+1].sum+tree[treenode*2].suffix);
    return ;
}



int32_t main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Write your code here
    int n,q;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    node *tree= new node[4*n];
    cin>>q;
    //o(n)
    buildtree(arr,tree,0,n-1,1);  

    // for(int i=1;i<4*n;i++)cout<<tree[i].sum<<" "<<tree[i].maxsum<<" "<<tree[i].prefix<<" "<<tree[i].suffix<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<getquery(tree,0,n-1,1,l-1,r-1).maxsum<<endl;;   
    }
    return 0;
}