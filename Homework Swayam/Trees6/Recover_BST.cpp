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
    TreeNode *prev=new TreeNode(INT_MIN) , *element1=NULL , *element2=NULL ;
    bool pair1found=false;
    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        //invalid
        if(root->val<prev->val && !pair1found){
            element1=prev;
            element2=root;
            pair1found=true;
        }
        else if(root->val < prev->val){
            element2=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=element1->val;
        element1->val=element2->val;
        element2->val=temp;
    }
};