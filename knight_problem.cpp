#include<bits/stdc++.h>
using namespace std;

 //knight problem
 //username-Mohit-2304


//Backtracking algorithm for Knight’s tour problem
// problem can also be solved by naive algorithm but backtracking gives a better solution 

//Please Note : The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once
 
bool can_place(int row,int col,int board[8][8])
 {
     return row<8&&col<8&&row>=0&&col>=0&&board[row][col]==0;
 }

 bool solve(int board[8][8],int move_no,int row,int col)
 {
     if(move_no==64)
     return true;

     int nextrow[]={-1,-2,-2,-1, 1, 2, 2, 1};
     int nextcol[]={ 2, 1,-1,-2,-2,-1, 1, 2};

     for(int i=0;i<8;i++)
     {
         int newrow=row+nextrow[i];
         int newcol=col+nextcol[i];

         bool check=can_place(newrow,newcol,board);

         if(check==true)
         {
             board[newrow][newcol]=move_no+1;

             bool correct=solve(board,move_no+1,newrow,newcol);

             if(correct==true)
             return true;

             board[newrow][newcol]=0;
         }
     }

     return false;
 }



 int main()
 {
    int board[8][8]={0},row=0,col=0;

    board[0][0]=1;

    bool print=solve(board,1,0,0);

    if(print==true)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            cout<<setw(3)<<board[i][j];

            cout<<"\n";
        }
    }

 }
