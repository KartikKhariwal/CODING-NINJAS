// 1ST METHOD(O(N)+O(1))

void swap(int&a,int&b){
  a=a^b;
  b=b^a;
  a=a^b;
}
void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
  for(int j=0;j<d/2;j++){
  swap(arr[j],arr[d-j-1]);
  }
   for(int i=0;i<(size-d)/2;i++){
  swap(arr[i+d],arr[size-i-1]);
  }
  for(int j=0;j<size/2;j++){
  swap(arr[j],arr[size-j-1]);
  }
 
}











//2ND method(O(N)+O(N))



void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
  int *temp=new int[d];
  for(int j=0;j<d;j++){
  temp[j]=arr[j];
  }
   for(int i=d;i<size;i++){
    arr[i-d]=arr[i];
  }
  for(int j=size-d;j<size;j++){
  arr[j]=temp[j-size+d];
  }
   

}	
	

//3rd METHOD(o(n^2))


// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
  for(int j=0;j<d;j++){
  int temp=arr[0];
   for(int i=1;i<size;i++){
    arr[i-1]=arr[i];
  }
   arr[size-1]=temp;
  }

}	

