#include<unordered_map>
	void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
     	unordered_map<int,int> mp;
      for(int i=0;i<n;i++){
        mp[input[i]]++;
      }
      for(int ct=0,i=0;i<n;i++){
        if(mp[input[i]]&&mp[-input[i]]){
          for(int j=0;j<mp[input[i]]*mp[-input[i]];j++)
          cout<<min(input[i],-input[i])<<" "<<max(input[i],-input[i])<<endl;
           mp[input[i]]=0;
           mp[-input[i]]=0;
        }
      }
 	}

