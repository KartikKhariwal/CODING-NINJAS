#include<bits/stdc++.h>
using namespace std;
#define int long long

//max product sub array code

int32_t main() {
    std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    // Write your code here
    int n;
    cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)cin>>v[i];

   int max_ending_here=1;
   int min_ending_here=1;
   int max_so_far=0;

   for(int i=0;i<n;i++){
        if(v[i]>0){
            max_ending_here*=v[i];
            min_ending_here=min(min_ending_here*v[i],1ll);
        }
        else if(!v[i]){
            max_ending_here=1;
            min_ending_here=1;
        }
        else{//v[i]<0
            int temp=max_ending_here;
            max_ending_here=max(min_ending_here*v[i],1ll),
            min_ending_here=temp*v[i];
        }
    max_so_far=max(max_so_far,max_ending_here);
   }
   cout<<max_so_far;
}