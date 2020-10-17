#include <string.h>
using namespace std;
string codes =" abcdefghijklmnopqrstuvwxyz";
int getint(char a){
    return a-48;
}

void print(string input,string output){
//basecase
 if(!input[0]){
     cout<<output<<endl;;
     return;
 }
    
 int b=-1,a=getint(input[0]);
 if(input[1]){
     b=a*10+getint(input[1]);
 }
  
  print(input.substr(1),output+codes[a]);
  if(b>=1&&b<=26)print(input.substr(2),output+codes[b]);
  
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    print(input,"");
}

