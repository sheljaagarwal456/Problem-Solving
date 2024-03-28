class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //base case
        if(root==NULL){
            return NULL;
        }
        //post-left right root --- iska ulta kardo
        invertTree(root->left);
        invertTree(root->right);
        TreeNode*temp=root->left; //temporary variable me left part daal diya jisse ki use baad mein right pe daalne me access kr sake 
        root->left=root->right; // left me right ka part
        root->right=temp ; // temp ka part right me ... right me left ka part
        return root;
    }
};