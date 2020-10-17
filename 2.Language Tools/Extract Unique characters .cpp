 #include<bits/stdc++.h>
char* uniqueChar(char *str){
    // Write your code here
set<char> s;
  char *a=str;
  string temp="";
  int i=0;
  while(*a!='\0'){
    if(s.find(*a)==s.end()){
      s.insert(*a);
      temp+=(*a);
    }
    a++;
  }
  char *cstr = new char[temp.length() + 1];
  strcpy(cstr, temp.c_str());
  return cstr;
}