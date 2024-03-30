/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool path(TreeNode* node, vector<int> &ans, int B){
    if (node==NULL) {
        return false;
    }
    ans.push_back(node->val);
    if (node->val==B) {
        return true;
    }
    if (path(node->left, ans, B) || path(node->right, ans, B)) {
        return true;
    }

    ans.pop_back();
    return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    path(A,ans,B);
    return ans;
}