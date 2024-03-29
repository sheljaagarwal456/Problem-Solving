class Solution {
public:
    //ek alag se function le liya jo humein return krega ans
    void path_Sum(TreeNode* root,vector<int>& v,vector<vector<int>>& ans , int targetSum){ // vector v to store path and ans to store all paths
        //base case 
        if(root==NULL){
            return;
        }
        //v me root daal diya 
        v.push_back(root->val);

        if(root->left==NULL && root->right==NULL && root->val==targetSum)
        {
            ans.push_back(v);
        }
        //recurssion
        path_Sum(root->left,v,ans,targetSum-root->val); // left me jao
        path_Sum(root->right,v,ans,targetSum-root->val); // right me jao
        v.pop_back(); //pop
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        //call the function
        path_Sum(root,v,ans,targetSum);
        return ans;
    }
};