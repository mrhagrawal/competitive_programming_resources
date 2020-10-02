/*
Weight and value of n items are given with a knapsack of capacity W. Find the maximum total value of items can be kept in knapsack of given capacity.
Here the items can't be divided.
*/
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n){
  int t[n+1][W+1];
  int i,j;
  for(i=0;i<=n;i++){
    for(j=0;j<=W;j++){
      if(i==0||j==0)  //base condition
        t[i][j]=0;
        else{
        if(wt[i-1]<=j)
        t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        else
        t[i][j]=t[i-1][j];
        }
    }
  }
  return t[n][W];
}
int main()
{
  int i,size,W;
  cin >> size;
  int value[size],Weight[size];
	for(i=0;i<size;i++)
    cin >> value[i];

  for(i=0;i<size;i++)
    cin >> Weight[i];

    cin >> W;
    int max_value=knapSack(W,Weight,value,size);
    cout << "The maximum value in the knapSack can be : "<<max_value << '\n';
  return 0;
}
