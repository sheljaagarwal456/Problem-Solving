#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[l]<=nums[mid]){
                if(target>=nums[l]&& target<=nums[mid]){
                    r=mid-1;
                }

                else{

                    l=mid+1;
                }
            }

            else{

                if(target>=nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
    int main(){
        return 0;
        vector<int> nums={4,5,6,7,0,1,2};
        int target=0;
        int ans=search(nums,target);
        cout<<ans<<endl;
    }