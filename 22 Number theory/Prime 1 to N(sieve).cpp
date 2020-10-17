#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE  O(n^1.5)
// int main(){
// 	// Write your code here
//     int n;
//     int count=0;
//     cin>>n;
//     for(int i=1;i<n;i++){
//         int flag=0;
//         for(int j=2;j*j<n;j++){
//             if(i%j==0){
//                 flag=1;
//                 break;
//             }
//         }
//         if(!flag)count++;
//     }
//     cout<<count;
// 	return 0;
// }



int sieve(int n){
    bool* arr=new bool[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=true;
    }
    
    arr[0]=0;arr[1]=0;
    int count =0;
    for(int i=2;i*i<=n;i++){
        //optimization 2 loop from 1 to rt(n) ans for>rt(n) they are already marked by nos till rt(n)
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i){ 
                //optimization 1 i.e j starting from i*i and not 2*i as 2i ,3i, ... (i-1)i are already checked by smaller nos  
                arr[j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(arr[i])count++;
    }
    delete []arr;
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<sieve(n);
    return 0;
    
}