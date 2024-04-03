//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode*solve(vector<int>&nums, int s, int e){
        // base condition
        if(s>e){
            return NULL;
        }

        int mid=(s+e) /2;
        //middle element is root of tree
        TreeNode*root=new TreeNode(nums[mid]);
        //left call for left elements of array
        root->left=solve(nums, s, mid-1);
        //right call for right elements of array
        root->right=solve(nums,mid+1 , e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //khali tree
        if(nums.size()==0){
            return NULL;
        }
        int start=0;
        int end=nums.size()-1;
        return solve(nums,start,end);
    }
};