 #include<bits/stdc++.h>
 using namespace std;
 template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

//function to traverse left side of tree
void traversalleft(TreeNode<int>*root, vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return ;
    }
    ans.push_back(root->data);
    //root->left exist kre toh wahan jao
    if(root->left){
        traversalleft(root->left,ans);
    }
    //left exist na kre toh right me jao
    else{
        traversalleft(root->right , ans); // otherwise right me jao
    }
}

// leaf nodes ke liye 
void traversalleaf(TreeNode<int>*root , vector<int>&ans){
    //base case
    if(root==NULL){
        return ;
    }
    // left right dono null hai mtlb leaf node hai toh store krlo use
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    //recurssion
    if(root->left) traversalleaf(root->left, ans);
    if(root->right)traversalleaf(root->right, ans);
}

// right part print krne ke liye function
void traversalright(TreeNode<int>*root , vector<int>&ans){
    if(root==NULL) {
        return;
    }
    if(root->left ==NULL&& root->right==NULL){
        return;
    }
    if(root->right){
        traversalright(root->right,ans);
    }
    else{
        traversalright(root->left,ans );
    }
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    //left part print
    traversalleft(root->left , ans);

    //leaf node of left subtree
    traversalleaf(root->left,ans);
    //leaf node of right subtree
    traversalleaf(root->right , ans);

    // right part print
    traversalright(root->right,ans);
    return ans;
    
}
