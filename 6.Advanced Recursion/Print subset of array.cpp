void print(int *input,int n,int *output,int id){
    if(n==0){
        for(int i=0;i<id;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    print(input+1,n-1,output,id);
    int *newop= new int[id+1];
    for(int i=0;i<id;i++){
        newop[i]=output[i];
    }
    newop[id]=input[0];
    print(input+1,n-1,newop,id+1);    
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code her
    int*output=new int[15];
print(input,size,output,0);
    
}



