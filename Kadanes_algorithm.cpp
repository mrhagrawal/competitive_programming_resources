/*
 The Idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array  And keep track of maximum sum contiguous(max_so_far) segment among all positive segments. Each time we get a positive sum compare it with maximum till now  and update it if it is greater than maximum and if the current_sum is less than 0 make it 0.
*/
#include<bits/stdc++.h>
using namespace std;
int max_subarray_sum(int a[],int size){
  int current_sum=0,max_so_far=INT_MIN;
  int i;
  for(i=0;i<size;i++){
    current_sum=current_sum+a[i];
    if(max_so_far<current_sum)
      max_so_far=current_sum;
    if(current_sum<0)
      current_sum=0;
  }
  return max_so_far;
}
int main(){
  int size,i;
  cin >> size;
  int arr[size];
  for(i=0;i<size;i++)
    cin >> arr[i];
  int max_sum=max_subarray_sum(arr,size);
  cout << "Maximum contiguous sum : "<<max_sum;
}
