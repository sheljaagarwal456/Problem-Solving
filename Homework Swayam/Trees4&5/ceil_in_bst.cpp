// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

#include<bits/stdc++.h>
using namespace std;
  
  struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceil=-1;
    while(root!=NULL){
        if(root->data==input){
            return root->data;
        }
        else if(root->data<input){
            root=root->right;
        }
        else{
            ceil=root->data; // store potential answer 
            root=root->left;
        }
    }
    return ceil;
}