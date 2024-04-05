#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//solution 
class Solution {
public:
    //code similar to binary tree can also work here
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // root dono se bada hai to left 
        if(root->val>p->val&& root->val>q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        // root dono se chota hai to right 
        if(root->val<p->val&& root->val<q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};



//code similar to binary tree can also work here
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // root dono se bada hai to left 
        if(root->val>p->val&& root->val>q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        // root dono se chota hai to right 
        if(root->val<p->val&& root->val<q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};