#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* temp(Node* node,unordered_map<Node*,Node*>& mp){
        Node*v=new Node(node->val);
        mp[node]=v;
        for(auto i:node->neighbors){
            //na mile toh create kr lo
            if(mp.find(i)==mp.end())
            {
                (v->neighbors).push_back(temp(i,mp));
            }
            else
            {
                (v->neighbors).push_back(mp[i]);
            }
        }
        return v;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }

        unordered_map<Node*,Node*>mp;
        return temp(node,mp);
        
    }
};