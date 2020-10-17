#include <bits/stdc++.h>
using namespace std;
#define X ((long long)(pow(10,9)+7))

long num_codes_i(int * input, int size) {
	long long* output = new long long[size + 1]();
	output[0] = 1;
	output[1] = 1;
        //output[i] gives no of codes for ith length of input
	for (int i = 2; i <= size; i++) {
        	if(input[i-1]>0)
			output[i] = output[i - 1];
			if ((input[i-2] ==1)||(input[i-2]==2 && input[i - 1] <7)) {
         			   output[i] =(output[i] +output[i - 2])%X;
			}
	}
	long ans = output[size];
	delete [] output;
	return ans;
}

int main()
{
    
    while(1){
        string n;
        cin>>n;
        if(n=="0")break;
        int*input=new int[n.length()];
        for(int i=0;i<n.length();i++){
            input[i]=n[i]-'0';
        }
        cout<<num_codes_i(input,n.length())<<endl;
//   
        
        
    }
    return 0;
}
