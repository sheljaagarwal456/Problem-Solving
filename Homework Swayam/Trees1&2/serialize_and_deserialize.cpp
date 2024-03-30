class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                s.append("null,");
            }
            else{
                s.append(to_string(node->val)+",");
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,','); //getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered. 
        TreeNode* root = new TreeNode(stoi(str)); //string to integer
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "null"){
                node->left = NULL;
            }
            else{
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            getline(s,str,',');
            if(str == "null"){
                node->right = NULL;
            }
            else{
                TreeNode* right= new TreeNode(stoi(str));
                node->right= right;
                q.push(right);
            }
        }
        return root;
    }
};