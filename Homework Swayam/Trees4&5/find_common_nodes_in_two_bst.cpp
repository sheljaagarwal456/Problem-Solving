
#include<bits/stdc++.h>
using namespace std;
  
  struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void insert(Node *root,set<int>&s)
    {
        if(root==NULL)return ;
        insert(root->left,s);
        s.insert(root->data);
        insert(root->right,s);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     set<int>s1,s2;
     insert(root1,s1);
     insert(root2,s2);
     
     vector<int>ans;
     for(auto i:s1)
     {
         if(s2.find(i)!=s2.end())
         ans.push_back(i);
     }
     return ans;
    }
};