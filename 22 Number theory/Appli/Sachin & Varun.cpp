#include<iostream>
using namespace std;
#define long long long


/*
    ax+by=d
    => ax=d-by
    => (d-by)%a=0   we need to find smallest y st this hold and then rem is y+ na <=d/b for diff n
    => d%a -(b%a)*(y%a)=0  
    also by=d-ax   => y=(d-ax)/b  => y%a = (d/b)%a - (ax/b)%a =(d/b)%a -0
    => y=(d/b)%a = (d%a)*(modinv(b,a))%a
    
    from here y+ na <=d/b
    n<=(d/b-y)/a 
    ans=n+1;(0 inc)
*/



class triplet{
    public:
    long x,y,gcd;
};

//Time comp O(Tlog(max(a,b)))
triplet extendedeuclid(long a,long b){
    //solving for ax+by =gcd(a,b)
    
    if(b==0){
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    
    triplet smallans=extendedeuclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x-((a/b)*(smallans.y));
    return ans;
}

long mmodInv(long a,long m){
    triplet ans=extendedeuclid(a,m);
    long x= ans.x;
    return (x%m+m)%m;
}

long gcd(long b,long a){
    return extendedeuclid(a,b).gcd;
}



int main(){
	// Write your code here
    int T;
    cin>>T;
    while(T--){
        long a,b,d;
        cin>>a>>b>>d;
        
        long g=gcd(a,b);
        //spl cases
        if(d%g!=0){
            cout<<0<<endl;
            continue;
        }
        if(d==0){
            cout<<1<<endl;
            continue;
        }
        a=a/g;
        b=b/g;
        d=d/g;
        //find y
        long y= ((d%a)*(mmodInv(b,a)))%a;  
       
        if(d < y*b){                      //n= (d/b   -y)/a   => d/b>y  if not then no soln
			cout << 0 <<endl;
			continue;
		}

        
        //find n
        long n=((d/b) - y)/a;
        
        cout<<n+1<<endl;
    }
    
    
	return 0;
}