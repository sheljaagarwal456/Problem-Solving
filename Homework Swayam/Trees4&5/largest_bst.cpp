#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    //function to check if tree is bst or not 
    bool valid(Node*root , int mini , int  maxi){
        if(root==NULL){
            return true;
        }
        if(root->data>mini && root->data<maxi){
            bool left =valid(root->left , mini, root->data );
            bool right=valid(root->right , root->data , maxi);
            return left&&right;
        }
        else{
            return false;
        }
    }
    
    //function to count no. of nodes
    int count(Node*root){
        if(root==NULL){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	if(root==NULL){
    	    return 0;
    	}
    	//root se shuru ho rha ho maybe humara bst
    	if(valid (root, INT_MIN , INT_MAX)){
    	    return count(root);
    	}
    	// root na ho toh left aur right ke liye check kr lo
    	int l=largestBst(root->left);
    	int r=largestBst(root->right);
    	
    	// largest return 
    	return max(l,r);
    }
};