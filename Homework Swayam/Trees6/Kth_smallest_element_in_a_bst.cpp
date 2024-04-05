#include <bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
//inorder nikal ke use  ek array me store krwa liya sabse pehle toh
    void inorder(TreeNode*root , vector<int>&arr){
        if(root==NULL){
            return ;
        }
        inorder(root->left ,arr );
        arr.push_back(root->val);
        inorder(root->right,arr );
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root , arr);
        return (arr[k-1]);
    }
};