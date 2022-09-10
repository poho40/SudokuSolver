#include<vector>;
using namespace std;


class Solution {
public:
    int N = 9;
    void solveSudoku(vector<vector<char>>& board) {
     solveS(board,0,0);
    }
bool solveS(vector<vector<char>>&board,int i,int j){
   if(i == board.size()) {
       return true;
   }
    if(j == board.size()){
        return solveS(board,i+1,0);
    }
    if(board[i][j] != '.') {
        return solveS(board,i,j+1);
    }
   for (char num = '1'; num <= '9'; num++){
      if (helper(board,i, j,num)){ 
         board[i][j] = num;
         if (solveS(board,i,j+1)) {
            return true;
         }
         board[i][j] = '.'; 
      }
   }
   return false;
}
    bool helper(vector<vector<char>>& board, int r, int c,char val) {
       for (int i =0 ; i < 9;i++) {
           if (board[i][c]==val) {
               return false; 
           }   
       }
       for (int i =0 ; i < 9;i++) {
           if (board[r][i]==val) {
               return false; 
           }   
       }
        int newI = (r/3)*3;
        int newJ= (c/3)*3;
        for (int i = newI; i < newI+3; i ++) {
          for (int j = newJ; j <newJ+3; j++) {
              if (!(i==r && j==c) && board[i][j] == val) {
                  return false; 
              }
          }
        }
        return true;
    }
};