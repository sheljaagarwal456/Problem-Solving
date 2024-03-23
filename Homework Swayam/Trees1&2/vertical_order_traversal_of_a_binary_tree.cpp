class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int> > >q;
        map<int,map<int,multiset<int>>>mp;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>>temp=q.front();
            q.pop();
            TreeNode*frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].insert(frontNode->val);
            if(frontNode->left!=NULL){
                q.push(make_pair(frontNode->left , make_pair(hd-1 , lvl+1)));
            }
            if(frontNode->right!=NULL){
                q.push(make_pair(frontNode->right , make_pair(hd+1 , lvl+1)));
            }
        }
        for(auto it:mp){
            vector<int>temp;
            for(auto i:it.second){
                for(auto j:i.second){
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};