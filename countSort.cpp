#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int init[100], rec[1000]={0}, j=0, n, i;
  cin >> n;
  for(i=0; i<n; i++)
  {
    cin >> init[i];
    rec[init[i]]++;
  }
  i=0;
  while(j<(*(&rec+1)-rec) && i<n)
  {
    if(rec[j]>0)
    {
      rec[j]--;
      init[i]=j;
      i++;
    }
    else
      j++;
  }
  for(i=0; i<n; i++)
  {
    cout << init[i] <<" ";
  }
  cout << endl;
  return 0;
}
