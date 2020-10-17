
void print(int input[], int n, int k,int *output,int id){
     
    if(n==0){
        if(k==0){
            for(int i=0;i<id;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        else return ;
    }
    else{
          int *newop= new int[id+1];
          for(int i=0;i<id;i++){
             newop[i]=output[i];
          }
          newop[id]=input[0];
          print(input+1,n-1,k-input[0],newop,id+1);
          print(input+1,n-1,k,output,id);
         
    }
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *output=new int[size];
    print(input,size,k,output,0);
   
}
