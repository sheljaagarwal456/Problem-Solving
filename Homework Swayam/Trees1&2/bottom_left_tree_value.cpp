class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //level order traversal
        //last level ka first element return krna hai
        TreeNode*ans=NULL; // isme humara ans aa jayega
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            ans=q.front();
            q.pop();
            //right hai toh vo daal do
            if(ans->right){
                q.push(ans->right);
            }
            if(ans->left){
                q.push(ans->left);
            }
        }
        return ans->val;
    }
};