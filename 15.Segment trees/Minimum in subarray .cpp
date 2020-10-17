#include<bits/stdc++.h>
using namespace std;
void updatequery(int *arr,int *tree,int start,int end,int treenode,int index,int value){
    if(start==end&&start==index){
        arr[index]=value;
        tree[treenode]=value;
        return ;
    }
    int mid=(start+end)/2;
    if(mid>=index){
        updatequery(arr,tree,start,mid,treenode*2,index,value);
    }
    else{
        updatequery(arr,tree,mid+1,end,treenode*2+1,index,value);
    }
    tree[treenode]=min(tree[treenode*2],tree[treenode*2+1]);
}

int getquery(int *tree,int start,int end,int treenode,int left,int right){
    
    //completely outside range
    if(start>right||end<left)return INT_MAX;
    
    //completely inside range
    if(start>=left&&end<=right)return tree[treenode];
    
    //partial inside and outside
    int mid=(start+end)/2;
    int ans1=getquery(tree,start,mid,treenode*2,left,right);
    int ans2=getquery(tree,mid+1,end,treenode*2+1,left,right);
    return min(ans1,ans2);
}

void buildtree(int *arr,int *tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode]=arr[start];
        return ;
    }
    
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,treenode*2);
    buildtree(arr,tree,mid+1,end,treenode*2+1);
    tree[treenode]=min(tree[treenode*2],tree[treenode*2+1]);
}

int main() {

	// Write your code here
    int n,q;
    cin>>n>>q;
    int *arr=new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int *tree= new int[4*n];
    
    //o(n)
    buildtree(arr,tree,0,n-1,1);
     // for(int i=1;i<4*n;i++)cout<<tree[i]<<" ";cout<<endl;
   // cout<< getquery(tree,0,n-1,1,0,2);
    while(q--){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='u'){ 
            //since we are using 0 indexeing l=l-1 
            updatequery(arr,tree,0,n-1,1,l-1,r);
            //A[l]=r for this query
            
        }else{
            //since we are using 0 indexeing l=l-1 and r=r-1
            cout<<getquery(tree,0,n-1,1,l-1,r-1)<<endl;
            //for getting min element in range l to r
        }
        
    }
}