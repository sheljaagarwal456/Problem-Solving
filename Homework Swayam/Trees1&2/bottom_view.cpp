
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if (root==NULL){
            return ans;
        }
        map<int,int>topnode;
        queue<pair<Node*,int>>q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node*frontnode=temp.first;
            int hd=temp.second;
            
            //if one value is present for hd, do nothing 
            topnode[hd]=frontnode->data;
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
};