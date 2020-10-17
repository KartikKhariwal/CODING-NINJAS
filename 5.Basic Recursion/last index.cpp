int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(size==0)return -1;
  	int t=lastIndex(input+1,size-1,x);
  	if(t==-1)
      if(input[0]!=x)return -1;
	  else return 1+t;
    else return 1+t;
  
}
