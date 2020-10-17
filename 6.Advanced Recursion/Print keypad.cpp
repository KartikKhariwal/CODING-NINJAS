#include <iostream>
#include <string>
using namespace std;
string options[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print(int num,string s){
    if(num<2){
        cout<<s<<endl;
        return ;
    }
    else {
        string cur=options[num%10];
        for(int i=0;i<cur.length();i++){
            print(num/10,cur[i]+s);
        }
    }
}



void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    print(num,"");
}
