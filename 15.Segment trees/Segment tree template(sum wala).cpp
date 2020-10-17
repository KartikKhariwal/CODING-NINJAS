#include <bits/stdc++.h>
using namespace std;
#define X (1000000007)

//SEGMENT TREE FOR GETTING SUM FROM RIGHT TO LEFT WITH UPDATE QUERIES

int getquery(const vector<int> &tree,int start,int end,int treenode,int left,int right){
    //COMPLETELY OUTSIDE GIVEN RANGE
    if(start>right||end<left){
        return 0;
    }

    //completely inside given range
    if(start>=left&&end<=right){
        return tree[treenode];
    }

    int mid=(start+end)/2;
    int ans1=getquery(tree,start,mid,treenode*2,left,right);
    int ans2=getquery(tree,mid+1,end,treenode*2+1,left,right);
    return ans1+ans2;
}

void updatetree(vector<int> &arr,vector<int> &tree,int start,int end,int treenode,int updatenode,int value){

    if(start==end&&start==updatenode){
        arr[updatenode]=value;
        tree[treenode]=value;
        return ;
    }
    int mid=(start+end)/2;

    if(mid>=updatenode){
        updatetree(arr,tree,start,mid,treenode*2,updatenode,value);
    }
    else{
        updatetree(arr,tree,mid+1,end,treenode*2+1,updatenode,value);
    }
    tree[treenode]=tree[treenode*2]+tree[treenode*2+1];

}


void buildtree(const vector<int> &arr,vector<int> &tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode]=arr[start];
                cout<<"*"<<treenode<<" "<<tree[treenode]<<endl;

        return;
    }
    
    int mid=(start+end)/2;

    buildtree(arr,tree,start,mid,treenode*2);
    buildtree(arr,tree,mid+1,end,2*treenode+1);

    //For sum queries of l to r
    tree[treenode]=tree[treenode*2]+tree[2*treenode+1];
}
int main()
{   std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> arr(n),segment_tree(4*n);

    for(int i=0;i<n;i++)cin>>arr[i];

    //O(n)time 
    buildtree(arr,segment_tree,0,n-1,1);

    //random update query to check working in O(logn)
    updatetree(arr,segment_tree,0,n-1,1,2,10);

    //random getsum wuery to check working in O(logn)
    int ans=getquery(segment_tree,0,n-1,1,2,4);
    cout<<ans<<endl;

    for(int i=1;i<4*n;i++)cout<<segment_tree[i]<<" ";
    

    
    return 0;
}
