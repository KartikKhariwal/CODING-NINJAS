class Triplet{
public:
	ll gcd;
	ll x;
	ll y;
};
Triplet gcdExtendedEuclid(ll a,ll b){
	//Base Case
	if(b==0){
		Triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;
		return myAns;

	}
	Triplet smallAns = gcdExtendedEuclid(b,a%b);
	//Extended euclid says

	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x  = smallAns.y;
	myAns.y = (smallAns.x - ((a/b)*(smallAns.y)));
	return myAns;	
}
 
ll modInverse(ll A, ll M)
{
    ll x = gcdExtendedEuclid(A, M).x;
    return (x % M + M) % M;
}