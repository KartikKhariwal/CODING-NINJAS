#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> input(1024);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        input[x]++;
    }    
    
  while(k--)  
  {   vector<int> temp(1024,0);
      for(int i=0,total=0;i<1024;i++){
          if(!input[i])continue;
        if(input[i]&1){
            if(total&1){
                temp[i^x]+=(input[i])/2;
                total+=input[i];
                input[i]-=(input[i])/2;
            }
            else{
                temp[i^x]+=(input[i]+1)/2;
                total+=input[i];
                input[i]-=(input[i]+1)/2;
            }
        }else{
            total+=input[i];
            input[i]/=2;
            temp[i^x]+=input[i];
        }
      }
   
   for(int i=0;i<1024;i++){
       //cout<<input[i]<<" ";
       input[i]+=temp[i];
   }
  }
    int low,max;
   for(int i=0;i<1024;i++){
       if(input[i]){
           low=i;break;
       }
   }
     for(int i=0;i<1024;i++){
       if(input[1023-i]){
           max=1023-i;break;
       }
   }
    cout<<max<<" "<<low;
    return 0;
}