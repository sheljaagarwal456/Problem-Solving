class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //0 elements in tree
        if(root==NULL){
            return false;
        }
        //1 element 
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            return true;
        }

        //recurssion 
        // dono subtree ka sum calcute krke check krlo ki taregt ke barabar mila ya nhi
        bool leftSum=hasPathSum(root->left , targetSum-root->val );
        bool rightSum=hasPathSum(root->right , targetSum-root->val );
        if(leftSum==true || rightSum ==true){
            return true;
        }
        return false;
    }
};
