#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> Answers ;
        vector<string> Table(n,string(n,'.'));
        Backtrack(Answers,Table,0,n);//start from 0 row
        return Answers;
    }
private:
    void Backtrack(vector<vector<string>> &Answers,vector<string> &Table,int row,int n){
        if(row == n){
            Answers.push_back(Table);
            return;
        }
        for(int col = 0; col<n;col++){
            if(isSafe(Table,row,col,n)){
                Table[row][col] = 'Q';
                Backtrack(Answers,Table,row+1,n);
                Table[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string> &Table,int row,int col,int n){
        //No need to check horizontal
        for(int i = 0;i<row;i++)//Vertical
            if (Table[i][col]=='Q')
                return false;

        for(int i = row , j = col ; i >= 0 && j>=0 ;i--,j--)//Diagonal to left from our row,col 
            if (Table[i][j]=='Q')
                return false;

        for(int i = row , j = col ; i >= 0 && j<n ;i--,j++)//Diagonal to right from our row,col 
            if (Table[i][j]=='Q')
                return false;
    
        return true;
    }
};

int main(){
    return -1;
}
