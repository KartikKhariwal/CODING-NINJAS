int binary(int* input ,int st,int end,int k){
  if(st>end)return -1;
  int mid=(end-st)/2+st;
  if(input[mid]==k)return mid;
  else if(input[mid]<k) return binary(input,mid+1,end,k);
  else return binary(input,st,mid-1,k);
  
  
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
  binary(input,0,size-1,element);

}
