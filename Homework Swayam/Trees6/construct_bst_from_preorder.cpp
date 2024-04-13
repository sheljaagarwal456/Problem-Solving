#include<bits/stdc++.h>
using namespace std;
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
    TreeNode*func(vector<int>&preorder, int maxi , int&i){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]>maxi){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[i++]);
        root->left=func(preorder, root->val , i);
        root->right=func(preorder, maxi , i);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return func(preorder , INT_MAX , i);
    }
};