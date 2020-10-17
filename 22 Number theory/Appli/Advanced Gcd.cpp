#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main(){
	// Write your code here
    
    // 345%b == (34*10  + 5)%b ==  ((3*10+4)*10 +5)%b ==(((0*10+3)*10+4)*10 +5)%b == after distribute b inside   (num*10 + curr digit)%b recc
	
    int T;
    cin>>T;
    while(T--){
        int a;
        cin>>a;
        string b;
        cin>>b;
        int num=0;
        
        //spl case when a=0
        if(a==0){
            cout<<b<<endl;
            continue;
        }
        
        //calculating b%a
        for(int i=0;b[i];i++){
            
            int digit=b[i]-'0';
            num = ((num%a)*((10)%a) + (digit)%a)%a;
            
        }
        
        cout<<gcd(num,a)<<endl;;
    }
    
    
    return 0;
}