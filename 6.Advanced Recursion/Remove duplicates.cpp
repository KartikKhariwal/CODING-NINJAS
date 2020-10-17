//REMOVE DUPLICATES


void remove(char *s,int newindex,int old){
  if(!s[old]){
    s[newindex++]=s[old-1];
    s[newindex]=s[old];
    return ;
  }
  else if(s[old]==s[old-1]){
    return remove(s,newindex,old+1);
  }
  else {
    s[newindex++]=s[old-1];
        return remove(s,newindex,old+1);

  }
  
  
  
}

void removeConsecutiveDuplicates(char *input) {
	
/*Solution 1
  

if(!input[1]||!input[0])return;
  else if(input[0]!=input[1]) return removeConsecutiveDuplicates(input+1);
  else{
    int i=1;
    for(;input[i];i++){
      input[i-1]=input[i];
    }
    input[i-1]='\0';
    return removeConsecutiveDuplicates(input);
  }
    */
  
  remove(input,(int)0,(int)1);

}