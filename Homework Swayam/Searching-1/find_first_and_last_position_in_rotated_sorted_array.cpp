class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //create ans vector
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if (nums[i]==target){
                ans.push_back(i);
                break;
            }
        }
        unordered_map<int,int>mp;
        //map elements with their indexes if elements are repeated it will automatic storre its latest index
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        //traverse in loop and check if it matches target than insert its index to ans
        for(auto i:mp){
            if(i.first==target){
                ans.push_back(i.second);
            }
        }
        //if ans empty
        if (ans.size()==0){
            return {-1,-1};
        }
        return ans;
    }
};
