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
           tree[treenode]+=(high-low+1)*lazytree[treenode];
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
      tree[treenode]+=(high-low+1)*increment;
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
     tree[treenode]=(tree[treenode*2]+tree[treenode*2+1]);
     return ;
}

int getquery(int low,int high,int treenode,int left,int right){
   
    if(low>high)return 0;  //completely useless 

    //updating current range and passing to children
    if(lazytree[treenode]!=0){
      tree[treenode]+=(high-low+1)*lazytree[treenode];
      if(low!=high)
      {
       lazytree[treenode*2]+=lazytree[treenode];
       lazytree[treenode*2+1]+=lazytree[treenode];
      }
      lazytree[treenode]=0;
    }

      //no overlap
     if(high<left||low>right) return 0 ;

     //complete overlap
     if(low>=left &&high<=right){
      return tree[treenode];
     }

     //partial overlap
     int mid=(low+high)/2;
     int ans1=getquery(low,mid,treenode*2,left,right);
     int ans2=getquery(mid+1,high,treenode*2+1,left,right);
     return ans1+ans2;
}

int32_t main()
{   std::ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    // #endif

    int t;
    cin>>t;
    while(t--)
{
    //input
    int n;
    cin>>n;
    int q;
    cin>>q;
       for(int i=0;i<4*n;i++){
          tree[i]=lazytree[i]=0;
        }
    while(q--){
      int s;
      cin>>s;

      if(s==0){
          int l,r,val;
          cin>>l>>r>>val;
             //updating both tree & lazy tree
             updateLAZY(0,n-1,l-1,r-1,1,val);
      }
      else{
        int l,r;
        cin>>l>>r;
        cout<<getquery(0,n-1,1,l-1,r-1)<<endl;;
      }
    }
}
 return 0;
}
