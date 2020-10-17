//METHOD 1


//o(n^3)

void FindTriplet(int input[], int n, int x) {
  
    for(int i=0;i<n-2;i++){
            int a=input[i];
      for(int j=i+1;j<n-1;j++){
        int b=input[j];
        for(int k=j+1;k<n;k++){
          int c=input[k];
          if(a+b+c==x){
             int mi=min(a,min(b,c));
          	 int ma=max(a,max(b,c));
          	cout<<mi<<" "<<a+b+c-mi-ma<<" "<<ma<<endl;
        }
        }
      }
    }
}



// METHOD 2(o(n^2))


void FindTriplet(int input[], int n, int x) {
  
    for(int i=0;i<n-2;i++){
            int a=input[i];
      for(int j=i+1;j<n-1;j++){
        int b=input[j];
        for(int k=j+1;k<n;k++){
          int c=input[k];
          if(a+b+c==x){
             int mi=min(a,min(b,c));
          	 int ma=max(a,max(b,c));
          	cout<<mi<<" "<<a+b+c-mi-ma<<" "<<ma<<endl;
        }
        }
      }
    }
}
