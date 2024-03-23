class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //ek ans array create kr lo
        vector<vector<int>>ans;
        //agar tree null hai to return null tree
        if(root==NULL){
            return ans;
        }
        //make a queue - FIFO
        queue<TreeNode*>q;
        //pehle q me root daal liya
        q.push(root);
        //traverse q
        while(!q.empty()){
            int s=q.size();
            //ek vector banaya to store the level order traversal
            vector<int>v;
            for(int i=0; i<s;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left); // left me jao
                }
                if(temp->right!=NULL){
                    q.push(temp->right); // right me jao
                }
                v.push_back(temp->val); // store one level with each iteration in array
            }
            ans.push_back(v);
        }
        return ans;
    }
};