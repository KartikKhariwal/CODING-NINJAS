#define input s

bool check(char * s){
 if(s[0]=='\0')return 1;
 else if(s[0]=='a'){
   if(s[1]=='a'||s[1]=='\0'){
     return check(input+1);
   }
   else if(s[1]=='b'&&s[2]&&s[2]=='b'){
          return check(input+2);
   }
   else return 0;
 }
  else{
    if(s[1]=='a'||!s[1]){
      return check(input+1);
    }
    else return 0;
  }
}

bool checkAB(char input[]) {
	// Write your code here
if(input[0]=='a'){
  return check(input);
}
  else return 0;
}



