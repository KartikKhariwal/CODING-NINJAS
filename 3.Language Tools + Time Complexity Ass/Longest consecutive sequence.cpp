#include<bits/stdc++.h>
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
  mp[arr[i]]++;
}
int largest_seq_ct=0,start=0;
for(int i=0;i<n;i++){
  if(mp[arr[i]-1]){
    continue;
  }
  else{
    int j=0;
    while(mp[arr[i]+j]){
      j++;
    }
    if(j>largest_seq_ct){
      largest_seq_ct=j;
      start=arr[i];
    }
  }
}
vector<int> v(largest_seq_ct);
iota(v.begin(),v.begin()+largest_seq_ct,start);
return v;
}