#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod(x)  ((x)%(1000000007))
#define N 1000000
vector<int> arr(N),tree(4*N,0),lazytree(4*N,0);

//SEGMENT TREE BY LAZY PROPOGATION for min elemnt and updation over range 

void updateLAZY(int low,int high,int left,int right,int treenode,int increment){

     if(low>high)return ;  //literally of no use
  
     //updating current range and passing to children
     if(lazytree[treenode]!=0){
           tree[treenode]+=lazytree[treenode];
         if(low!=high)
         {  lazytree[treenode*2]+=lazytree[treenode];
            lazytree[treenode*2+1]+=lazytree[treenode];
         }
           lazytree[treenode]=0;
     }

     //no overlap
     if(high<left||low>right) return ;

     //complete overlap
     if(low>=left &&high<=right){
      tree[treenode]+=increment;
      if(low!=high)
      {  lazytree[treenode*2]+=increment;
         lazytree[treenode*2+1]+=increment;
      }
      return ;
     }

     //partial overlap
     int mid=(low+high)/2;

     updateLAZY(low,mid,left,right,treenode*2,increment);
     updateLAZY(mid+1,high,left,right,treenode*2+1,increment);
     tree[treenode]=min(tree[treenode*2],tree[treenode*2+1]);
     return ;
}

int getquery(int low,int high,int treenode,int left,int right){
   
    if(low>high)return INT_MAX;  //completely useless 

    //updating current range and passing to children
    if(lazytree[treenode]!=0){
      tree[treenode]+=lazytree[treenode];
      if(low!=high)
      {
       lazytree[treenode*2]+=lazytree[treenode];
       lazytree[treenode*2+1]+=lazytree[treenode];
      }
      lazytree[treenode]=0;
    }

      //no overlap
     if(high<left||low>right) return INT_MAX ;

     //complete overlap
     if(low>=left &&high<=right){
      return tree[treenode];
     }

     //partial overlap
     int mid=(low+high)/2;
     int ans1=getquery(low,mid,treenode*2,left,right);
     int ans2=getquery(mid+1,high,treenode*2+1,left,right);
     tree[treenode]=min(ans1,ans2);
     return tree[treenode];
}

void buildtree(int start,int end,int treenode){
    if(start==end){
        tree[treenode]=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    buildtree(start,mid,treenode*2);
    buildtree(mid+1,end,2*treenode+1);
    //For min from l to r
    tree[treenode]=min(tree[treenode*2],tree[2*treenode+1]);
}
int32_t main()
{   std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    //input
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int q;
    cin>>q;

    //O(n)time 
    buildtree(0,n-1,1);


    while(q--){
      int t;cin>>t;
      if(t==1){
          int l,r,val;
          cin>>l>>r>>val;
             //updating both tree & lazy tree
             updateLAZY(0,n-1,l,r,1,val);
      }
      else{
        int l,r;
        cin>>l>>r;
        cout<<getquery(0,n-1,1,l,r)<<endl;;
      }

    }


    

    
    return 0;
}
