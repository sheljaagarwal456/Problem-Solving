class Solution {
public:

    void paths(TreeNode*root, int targetSum , vector<int>path , int &cnt){
        //base case
        if(root==NULL){
            return ;
        }
        path.push_back(root->val);

        //recurssion
        paths(root->left, targetSum, path , cnt);
        paths(root->right, targetSum, path , cnt);

        //check kro sum target ke equal hai ki nhi
        long long sum=0; // long long lenge jisse sum zyda bhi aaye toh store kr paaye
        int s=path.size();
        for(int i=s-1 ;i>=0;i--){
            sum=sum+path[i];
            if(sum==targetSum){
                cnt++;
            }

        }
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        vector<int>path;
        paths(root, targetSum, path , cnt);
        return cnt;
    }
};