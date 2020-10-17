#include <string.h>
using namespace std;
string codes =" abcdefghijklmnopqrstuvwxyz";
int getint(char a){
    return a-48;
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
//basecase
 if(!input[0]){
     output[0]="";
     return 1;
 }
    
 int b=-1,a=getint(input[0]);
 if(input[1]){
     b=a*10+getint(input[1]);
 }
  
  string newout[10000];
  int x=getCodes(input.substr(1),newout);
  for(int i=0;i<x;i++){
      output[i]=codes[a]+newout[i];
  }
  if(b>=1&&b<=26){   
  int y=getCodes(input.substr(2),newout);
  for(int i=0;i<y;i++){
      output[i+x]=codes[b]+newout[i];
  }
      return x+y;
  }
    
    return x;
    
}

