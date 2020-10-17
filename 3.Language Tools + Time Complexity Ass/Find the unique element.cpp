// arr - input array
// size - size of array

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  int p=0;
  for(int i=0;i<size;i++){
    p=p^arr[i];
  }
  return p;
}