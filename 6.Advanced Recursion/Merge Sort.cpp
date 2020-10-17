void merge(int *v ,int start,int mid,int end){
  int * temp=new int[end-start+1];
  int i=start,j=mid,k=0;
  while(i<mid&&j<=end){
    if(v[i]>v[j]){
      temp[k++]=v[j++];
    }else{
      temp[k++]=v[i++];
    }
  }
  while(i<mid){
    temp[k++]=v[i++];
  }
  while(j<=end){
    temp[k++]=v[j++];
  }
  for(int i=start,k=0;i<=end;i++){
    v[i]=temp[k++];
  }
  return;
  
}
void sort(int *input,int start,int end){
  	
  if(start>=end)return ;
  sort(input,start,(start+end)/2);
  sort(input,1+(start+end)/2,end);
  merge(input,start,(start+end+2)/2,end);
  
  
}



void mergeSort(int input[], int size){
	// Write your code here
    sort(input,0,size-1);
}
