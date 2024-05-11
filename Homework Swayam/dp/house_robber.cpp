#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int temp1=0; // dp[i - 1]
    int temp2=0; // dp[i - 2]

    for (int it:nums) {
      int dp=max(temp1,temp2+it);
      temp2=temp1;
      temp1=dp;
    }

    return temp1;
  }
};