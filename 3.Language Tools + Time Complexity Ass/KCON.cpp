//https://www.codechef.com/submit/KCON


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadaneSum(int arr[],int n)
{
    ll curr_sum=0;
    ll max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum = curr_sum+arr[i];
        if(max_sum<curr_sum)
        {
            max_sum = curr_sum;
        }
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}
ll maxSubarraySum(int arr[],int n,int k)
{
    ll k_sum= kadaneSum(arr,n);
    if(k == 1)
    {
        return k_sum;
    }
    ll curr_prefix_sum=0; ll curr_suffix_sum=0;
    ll max_prefix_sum=INT_MIN; ll max_suffix_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_prefix_sum = curr_prefix_sum + arr[i];
        if(max_prefix_sum < curr_prefix_sum)
           max_prefix_sum = curr_prefix_sum;
    }
     ll total_sum = curr_prefix_sum;
    for(int i=n-1;i>=0;i--)
    {
        curr_suffix_sum = curr_suffix_sum + arr[i];
        if(max_suffix_sum < curr_suffix_sum)
          max_suffix_sum = curr_suffix_sum;
    }
    ll ans;
   if(total_sum<0)
   {
       ans = max(max_prefix_sum+max_suffix_sum, k_sum);
   }
   else
   {
      ans = max(max_prefix_sum + max_suffix_sum + (total_sum*(k-2)), k_sum);
   }
   return ans;
}
int main() {
	int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<maxSubarraySum(arr,n,k)<<endl;
	}
	return 0;
}
