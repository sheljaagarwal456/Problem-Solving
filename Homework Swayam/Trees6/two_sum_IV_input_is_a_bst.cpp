#include<bits/stdc++.h>
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

    //ek function bana ke usme array pass krke two pointer approach se sum check krlo ki equal aaya ya ni
    bool sum( TreeNode *root, vector<int>&ans , int k){
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k){
                return true;
            }
            else if(ans[i]+ans[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        return sum(root,arr,k);
    }
};