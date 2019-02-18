#include<bits/stdc++.h>
using namespace std;
#define lint long long 

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,vector<lint> > mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i+1);
        }
        int odd=0;
        for(auto x:mp){
            if(x.second.size()%2){odd++;}
        }
        if(odd>1){
            cout<<-1<<endl;
        }
        else{
              vector<lint> op(s.length(),-12);
              int j=0,k=s.length()-1,save;
              
              for(auto x:mp){
                   for(int i=(x.second.size()%2?1:0);i<x.second.size();i++){
                    if(i%2)op[j++]=x.second[i];
                    else op[k--]=(x.second[i]);
                }
              if(x.second.size()%2!=0){
                 save=x.second.front();
                 }
              }
            
              for(int i=0;i<op.size();i++){
            if(i==op.size()/2&&odd){cout<<save<<" ";continue;}
            cout<<op[i]<<" ";
           
        }
                cout<<endl;
        }
                }
         	return 0;
}
