#include <bits/stdc++.h> 
using namespace std; 
  

void printMatrix(vector<string>& matrix, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << matrix[i] << endl; 
} 


// this function checks for the current word if it can be placed horizontally or not 
// x -> it represent index of row 
// y -> it represent index of column 
// currentWord -> it represent the current word in word array 
vector<string> checkHorizontal(int x, int y,vector<string> matrix,string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x][y + i] == '-' ||matrix[x][y + i] == currentWord[i]) { 
            matrix[x][y + i] = currentWord[i]; 
        } 
        else {  
            // this shows that word cannot be placed horizontally 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
  
    return matrix; 
} 
  
// this function checks for the current word if it can be placed vertically or not 
// x -> it represent index of row // y -> it represent index of column 
// currentWord -> it represent the current word in word array 
vector<string> checkVertical(int x, int y,vector<string> matrix,string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x + i][y] == '-' || matrix[x + i][y] == currentWord[i]) { 
            matrix[x + i][y] = currentWord[i]; 
        } 
        else { 
            // this shows that word cannot be placed vertically 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
    return matrix; 
} 
  
// this function recursively checks for every word that can align vertically in one loop 
// and in another loop it checks for those words that can align horizontally
//words -> it contains all the words to fill in a crossword puzzle matrix -> it contain the current 
// state of crossword 
//index -> it represent the index of current word 
//n -> it represent the length of row or column of the square matrix 
void solvePuzzle(vector<string>& words,vector<string> matrix,int index, int n) 
{ 
    if (index < words.size()) { 
        string currentWord = words[index]; 
        int maxLen = n - currentWord.length(); 
  
        // loop to check the words that can align vertically. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkVertical(j, i,matrix, currentWord); 
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
  
        // loop to check the words that can align horizontally. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkHorizontal(i, j,matrix, currentWord); 
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
    } 
    else { 
                printMatrix(matrix, n); 
        return; 
    } 
} 


using namespace std;
int main() {
    vector<string> v(10),words;
    for(int i=0;i<10;i++){
        cin>>v[i];
    }
    string s;
    cin>>s;
    int i=0,si=0;
    while(s[i]){
        if(s[i]==';'){
            words.push_back(s.substr(si,i-si));
            si=i+1;
        }
        i++;
    }
    words.push_back(s.substr(si));
	solvePuzzle(words,v,0,10);
  
}