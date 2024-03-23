class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;
    }
};