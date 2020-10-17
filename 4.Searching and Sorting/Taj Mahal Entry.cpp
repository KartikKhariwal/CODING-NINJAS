#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;cin>>n;
   vector<long long int> v(n);
   for(int i=0;i<n;i++)cin>>v[i];
  long long int i,j; 
  for( i=0,j=0;;i=(i+1)%(n),j++){
     if(v[i]-j<=0){
       cout<<i+1;break;
     }
   }
    
	return 0;
}




/*METHOD 2

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;cin>>n;
   vector<long long> v(n);
   for(int i=0;i<n;i++)cin>>v[i];
  long long i,j; 
  for(int i=0;i<n;i++){
    long long x=(v[i]-i)/n+((v[i]-i)%n&&v[i]-i>0?1:0);
    v[i]=n*x+i;
  }
  cout<<(min_element(v.begin(),v.end())-v.begin())+1;
    
	return 0;
}





*/ //METHOD 3 BINARY SEARCH ON T