#include<bits/stdc++.h>
using namespace std;
bool sol=0;

void printSolution(int** solution,int n){
//	sol=1;
	cout<<endl<<"--- Solution Found --- \n\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y,int num){
//	if(sol)return ;
	if(x == n-1 && y == n-1){
		solution[x][y] =num;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] !=0){
		return;
	}
	solution[x][y] = num;
	mazeHelp(maze,n,solution,x-1,y,num+1);
	mazeHelp(maze,n,solution,x+1,y,num+1);
	mazeHelp(maze,n,solution,x,y-1,num+1);
	mazeHelp(maze,n,solution,x,y+1,num+1);
	solution[x][y] = 0;
}
void Maze(int maze[][20], int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n]();
  }
  mazeHelp(maze,n,solution,0,0,1);


}
int main(){
	cout<<"Enter size of maze : ";
	int n;
	cin>>n;
	int maze[20][20];
	cout<<"\n Now enter the maze : \n";
	for(int i=0;i<n;i++){
//		maze[i]=new int[20];
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	Maze(maze,n);
	return 0;
	
}
