#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/

    
    if(!input[0]){
        output[0]="";
        return 1;
    }
    else {
        int k=0;
         for(int i=0;i<input.length();i++){
             char first=input[i];
             string newoutput[5000];
             int x=returnPermutations(input.substr(0,i)+input.substr(i+1),newoutput);
             for(int j=0;j<x;j++){
                 output[k++]=first+newoutput[j];
             }
         }   
        
        return k;
    }    
     
    
    
    /*Solution 2
    if(!input[0]){
        output[0]="";
        return 1;
    }
    else {
                string newout[10000];
        int a=returnPermutations(input.substr(1),newout);
        int k=input.length();
        int x=0;
        
        for(int i=0;i<a;i++){
            for(int j=0;j<k;j++){
                output[x++]=newout[i].substr(0,j)+input[0]+newout[i].substr(j);
            }
        }
        
        return x;
    }
    */
    

    
    
}
