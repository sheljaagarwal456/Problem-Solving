#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        //size=1
        if(n==1){
            return nums[0];
        }

        //ans is first element
        if(nums[0]!=nums[1]){
            return nums[0];
        }

        //ans is last element
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        //binary search
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
               return nums[mid];
            }

            //right part me kab jaana hoga
            else if(mid%2!=0 && nums[mid-1]==nums[mid]  ||  mid%2==0 && nums[mid]==nums[mid+1]){
                s=mid+1;
            }
            //left me kab jaana hoga
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
};