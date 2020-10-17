//Quick Sort

/*
int partition_2(int *v,int p,int r){
    if(p==r)return p;
    int key=v[p];
    int x=key;
    int ct=0;
    for(int i=p+1;i<=r;i++){
        if(v[i]<=key)ct++;
    }
    v[p]=v[p+ct];
    v[p+ct]=key;
    int i=p;
    int j=r;
    while(i!=p+ct&&j!=p+ct){
        if(v[i]<=x){
            i++;
        }
        else if(v[j]>x){
            j--;
        }
        else{
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
    }
    
    
    return p+ct;
}

*/


int partition(int *v,int p,int r){
    if(p==r)return p;
    int key=v[r];
    int i=p-1;
    int j=p;
    while(j!=r){
        if(v[j]<v[r]){
            i++;
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
        j++;
    }
    i++;
    v[r]=v[i];
    v[i]=key;
    return i;
}


void qs(int *v,int p ,int r){
    if(p<=r){
    int q=partition(v,p,r);
    qs(v,p,q-1);
    qs(v,q+1,r);
    }
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    qs(input,0,size-1);
}
