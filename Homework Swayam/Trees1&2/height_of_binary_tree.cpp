int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL){
        return NULL;
    }
    int left=heightOfBinaryTree(root->left);
    int right=heightOfBinaryTree(root->right);
    return max(left,right)+1;
}