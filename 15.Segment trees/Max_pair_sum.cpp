#include<bits/stdc++.h>
using namespace std;
#define int long long

void updatequery(int *arr,pair<int,int> *tree,int start,int end,int treenode,int index,int value){
    if(start==end&&start==index){
        arr[index]=value;
        tree[treenode]={value,INT_MIN};
        return ;
    }
    int mid=(start+end)/2;
    if(mid>=index){
        updatequery(arr,tree,start,mid,treenode*2,index,value);
    }
    else{
        updatequery(arr,tree,mid+1,end,treenode*2+1,index,value);
    }
    tree[treenode].first=max(tree[treenode*2].first,tree[treenode*2+1].first);
    tree[treenode].second=min(max(tree[treenode*2].first,tree[treenode*2+1].second),max(tree[treenode*2].second,tree[treenode*2+1].first));
    return ;
}

pair<int,int> getquery(pair<int,int> *tree,int start,int end,int treenode,int left,int right){
    
    //completely outside range
    if(start>right||end<left)return {INT_MIN,INT_MIN};
    
    //completely inside range
    if(start>=left&&end<=right)return tree[treenode];
    
    //partial inside and outside
    int mid=(start+end)/2;
    pair<int,int> ans1=getquery(tree,start,mid,treenode*2,left,right);
    pair<int,int> ans2=getquery(tree,mid+1,end,treenode*2+1,left,right);
    
    int ans3=max(ans1.first,ans2.first);
    int ans4=min(max(ans1.first,ans2.second),max(ans1.second,ans2.first));
    return {ans3,ans4};
}

void buildtree(int *arr,pair<int,int> *tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode]={arr[start],INT_MIN};
        return ;
    }
    
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,treenode*2);
    buildtree(arr,tree,mid+1,end,treenode*2+1);
   
    tree[treenode].first=max(tree[treenode*2].first,tree[treenode*2+1].first);
    tree[treenode].second=min(max(tree[treenode*2].first,tree[treenode*2+1].second),max(tree[treenode*2].second,tree[treenode*2+1].first));
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
    pair<int,int> *tree= new pair<int,int>[4*n];
    cin>>q;
    //o(n)
    buildtree(arr,tree,0,n-1,1);
    while(q--){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='U'){ 
            //since we are using 0 indexeing l=l-1 
            updatequery(arr,tree,0,n-1,1,l-1,r);
            //A[l]=r for this query
            
        }else{
            //since we are using 0 indexeing l=l-1 and r=r-1   
            --l;--r;
            pair<int,int> xy=getquery(tree,0,n-1,1,l,r);
            cout<<xy.first+xy.second<<endl;
            //for getting max sum element in range l to r
        }
        
    }
    return 0;
}