#include<bits/stdc++.h>
using namespace std;
int countless(vector<vector<int> > &A, int num)
{
    //function to count elements less or equal to num
int n = A.size();
int m = A[0].size();
int cnt=0;
for(int i=0;i<n;i++)
{
    int low=0,high=m-1;
    while(low<high)
    {
        int mid= (low+high)/2;
        if(A[i][mid] <= num)
            low=mid+1;
        else if(A[i][mid] > num)
            high=mid;
    }
    if(A[i][low] <= num)
        cnt+=low+1;
    else
        cnt+=low;
}
return cnt;
}
int Solution::findMedian(vector<vector<int> > &A) {
     int low = INT_MAX;
  int high = INT_MIN;
  int n = A.size();
  int m = A[0].size();
  int k=(n*m)/2; //let k be the mid element
  for(int i=0;i<n;i++){
    //assign lowest and highest value as matrix is sorted row wise 
    low=min(low, A[i][0]);
    high= max(high, A[i][m-1]);
  }

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = countless(A,mid);
    //if count is greater than go to left part
    if(cnt >= (k+1))
        high=mid-1;
        // else go to right pasrt
    else if(cnt < (k+1))
        low=mid+1;
  }
  return low;
}