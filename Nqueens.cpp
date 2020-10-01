//jatiny17
//Jatin Kumar

#include<bits/stdc++.h>
using namespace std;

//n-queen problem

bool canplace(int board[10][10],int n,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col]==1)
        return false;
    }

    int i=row,j=col;

    while(i>=0&&j>=0)
    {
        if(board[i][j]==1)
        return false;

        i--;
        j--;
    }

    i=row,j=col;

    while(i>=0&&j<n)
    {
        if(board[i][j]==1)
        return false;

        i--;
        j++;
    }

    return true;
}

bool queen(int board[10][10],int n,int row)
{
    if(row==n)
    {
        return true;
    }

    for(int i=0;i<n;i++)
    {
        if(canplace(board,n,row,i))
        {
            board[row][i]=1;

            bool next=queen(board,n,row+1);

            if(next==true)
            return true;

            board[row][i]=0;
        }
    }

    return false;
}


int main()
{
    int board[10][10]={0},n;

    cin>>n;

    bool check=queen(board,n,0);

    if(check)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                cout<<" Q";

                else
                cout<<" _";
            }

            cout<<"\n";
        }
    }

}
