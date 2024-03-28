class Solution {
public:
    void solve(TreeNode*root , vector<string>&ans , string s){
        //base case
        if(root==NULL){
            return ;
        }
        //convert node to string and add->
        s=s+to_string(root->val);
        s=s+"->";
        if(root->left==NULL && root->right==NULL){
            s.erase(s.length()-2); // last me-> nhi chahiye h
            ans.push_back(s);
            return;
        }
        //recurssion
        solve(root->left , ans,s);
        solve(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        //string form me answer store krna hai to array bana liya string ka
        vector<string>ans;
        string s="";
        solve(root,ans,s);
        return ans;
    }
};