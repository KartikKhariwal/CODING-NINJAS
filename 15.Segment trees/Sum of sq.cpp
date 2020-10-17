#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod(x)  ((x)%(1000000007))
#define N 1000000

struct node{
  int value;
  int type;
};
struct node1{
  int sum;
  int sqsum;
};
vector<int> arr(N);
vector<node> lazytree(4*N,{0,0});
vector<node1> tree(4*N,{0,0});

//SEGMENT TREE BY LAZY PROPOGATION for sum of squares 

void updateLAZY(int low,int high,int left,int right,int treenode,int value,int type){

     if(low>high)return ;  //literally of no use
  
     //updating current range and passing to children
     if(lazytree[treenode].type!=0){
        if(lazytree[treenode].type==1){
              tree[treenode].sqsum=(high-low+1)*(lazytree[treenode].value)*(lazytree[treenode].value);
              tree[treenode].sum= (high-low+1)*(lazytree[treenode].value);
              if(low!=high)
             {     
                long id =treenode;
                lazytree[2*id].type = 1;
                lazytree[2*id].value = lazytree[id].value;
                lazytree[2*id+1].type = 1;
                lazytree[2*id+1].value = lazytree[id].value;
             }
        }else{
            tree[treenode].sqsum +=(high-low+1)*(lazytree[treenode].value)*(lazytree[treenode].value) + 2*(lazytree[treenode].value)*(tree[treenode].sum) ;

            tree[treenode].sum +=(high-low+1)*(lazytree[treenode].value);
            if(low!=high)
             {   long  id=treenode;
                lazytree[treenode*2].type=((lazytree[treenode*2].type==1)?1:2);
                lazytree[treenode*2+1].type=((lazytree[treenode*2+1].type==1)?1:2);
                lazytree[2*id].value += lazytree[id].value;
                lazytree[2*id+1].value += lazytree[id].value;

             }
        }
           lazytree[treenode]={0,0};
     }


     //no overlap
     if(high<left||low>right) return ;

     //complete overlap
     if(low>=left &&high<=right){
      
      if(type==1){
              tree[treenode].sqsum =(high-low+1)*value*value;
              tree[treenode].sum=(high-low+1)*value;
      if(low!=high)
         {  lazytree[treenode*2].type=1;
            lazytree[treenode*2].value=value;
            lazytree[treenode*2+1].type=1;
            lazytree[treenode*2+1].value=value;
         }
        }
      else{
            tree[treenode].sqsum +=(high-low+1)*value*value + 2*(value)*(tree[treenode].sum) ;
            tree[treenode].sum+= (high-low+1)*value;
            if(low!=high)
         {  lazytree[treenode*2].type=((lazytree[treenode*2].type==1)?1:2);
            lazytree[treenode*2+1].type=((lazytree[treenode*2+1].type==1)?1:2); 
            lazytree[treenode*2].value+=value;
            lazytree[treenode*2+1].value+=value;
         }
        } 
      return ;
     }

     //partial overlap
     int mid=(low+high)/2;

     updateLAZY(low,mid,left,right,treenode*2,value,type);
     updateLAZY(mid+1,high,left,right,treenode*2+1,value,type);
     tree[treenode].sqsum=(tree[treenode*2].sqsum+tree[treenode*2+1].sqsum);
     tree[treenode].sum=tree[treenode*2].sum+tree[treenode*2+1].sum;
     return ;
}

node1 getquery(int low,int high,int treenode,int left,int right){

    if (low>high)return {0,0};
   
       //updating current range and passing to children
     if(lazytree[treenode].type!=0){
        if(lazytree[treenode].type==1){
              tree[treenode].sqsum=(high-low+1)*(lazytree[treenode].value)*(lazytree[treenode].value);
              tree[treenode].sum= (high-low+1)*(lazytree[treenode].value);
              if(low!=high)
             {     
                long id =treenode;
                lazytree[2*id].type = 1;
                lazytree[2*id].value = lazytree[id].value;
                lazytree[2*id+1].type = 1;
                lazytree[2*id+1].value = lazytree[id].value;
             }
        }else{
            tree[treenode].sqsum +=(high-low+1)*(lazytree[treenode].value)*(lazytree[treenode].value) + 2*(lazytree[treenode].value)*(tree[treenode].sum) ;

            tree[treenode].sum +=(high-low+1)*(lazytree[treenode].value);
            if(low!=high)
             {     long id=treenode;
                lazytree[treenode*2].type=((lazytree[treenode*2].type==1)?1:2);//dont ignore this bullshit
                lazytree[treenode*2+1].type=((lazytree[treenode*2+1].type==1)?1:2);
                lazytree[2*id].value += lazytree[id].value;
                lazytree[2*id+1].value += lazytree[id].value;

             }
        }
           lazytree[treenode]={0,0};
     }



     //no overlap
     if(high<left||low>right) return {0,0};

     //complete overlap
     if(low>=left &&high<=right){
      return tree[treenode];
     }

     //partial overlap
     int mid=(low+high)/2;
     node1 ans1=getquery(low,mid,treenode*2,left,right);
     node1 ans2=getquery(mid+1,high,treenode*2+1,left,right);
     node1 temp;
     temp.sum=ans1.sum+ans2.sum;
     temp.sqsum=ans1.sqsum+ans2.sqsum;
     return temp;
}

void buildtree(int start,int end,int treenode){
    if(start==end){
        tree[treenode].sqsum=arr[start]*arr[start];
        tree[treenode].sum=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    buildtree(start,mid,treenode*2);
    buildtree(mid+1,end,2*treenode+1);
    //For min from l to r
    tree[treenode].sum=tree[treenode*2].sum+tree[treenode*2+1].sum;
    tree[treenode].sqsum=tree[treenode*2].sqsum+tree[treenode*2+1].sqsum;
}


int32_t main()
{   std::ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    // #endif
    int t;
    cin>>t; 

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":\n";
        //input
        int n,q;
        cin>>n>>q;
        for(int i=0;i<4*n;i++){
          tree[i]={0,0};
          lazytree[i]={0,0};
        }
        for(int i=0;i<n;i++){
          cin>>arr[i];
        }

        //O(n)time 
        buildtree(0,n-1,1);
       
        while(q--){
          int type;
          cin>>type;
          if(type==0||type==1){
                 int l,r,val;
                 cin>>l>>r>>val;
                 //updating both tree & lazy tree
                 updateLAZY(0,n-1,l-1,r-1,1,val,type+1);
          }
          else{
            int l,r;
            cin>>l>>r;
            cout<<getquery(0,n-1,1,l-1,r-1).sqsum<<endl;;
          }
    
        }
    
    }
    

    
    return 0;
}
