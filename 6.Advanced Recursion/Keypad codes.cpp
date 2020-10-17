#include <string>
using namespace std;

string getstring(int x){
    if(x<2){
      return "";
    }
    else if(x==2){
        return "abc";
    }
    else if(x==3){
        return "def";
    }
    else if(x==4){
        return "ghi";
    }
    else if(x==5){
        return "jkl";
    }
    else if(x==6){
        return "mno";
    }
    else if(x==7){
        return "pqrs";
    }
    else if(x==8){
        return "tuv";
    }
    else return "wxyz";
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    int ct=keypad(num/10,output);
    string s=getstring(num%10);
    for(int i=1;i<s.length();i++){
        for(int j=ct*i,k=0;j<ct*i+ct;j++ ){
            output[j]=output[k++];
        }
    }
    for(int i=0;i<s.length();i++){
        for(int j=ct*i;j<ct*i+ct;j++){
            output[j]=output[j]+s[i];
        }
    }
    return s.length()*ct;
}
