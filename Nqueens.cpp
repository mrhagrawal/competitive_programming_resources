//Jatin Kumar
//jatiny17

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

//n-queen problem

// Function for checking if a queen could be placed on a position (row ,col) without getting in line with other already placed queens
bool canplace(vector< vector<int> >&board,int n,int row,int col)
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

// recursive fcuntion for generating a permutation of the n queens 
bool queen(vector< vector<int> >&board,int n,int row)
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
    fast;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif   

    int n;
    cin>>n;

    if(n<=0)
    {
        cout<<"Enter a legitimate size of the board (>=1)\n";
        return 0;
    }

    vector< vector<int> > board(n, vector<int> (n,0));

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
