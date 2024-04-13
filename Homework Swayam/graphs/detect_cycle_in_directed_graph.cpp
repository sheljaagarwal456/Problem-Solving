#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        bool dfs(int node , vector<int>adj[], int vis[] , int pathVis[]){
            vis[node]=1;
            pathVis[node]=1;
            // traverse adjacent node
            for(auto it:adj[node]){
                if(!vis[it]){
                    if(dfs(it , adj , vis , pathVis)==true){
                        return true;
                    }
                }
                //if node has been visited already 
                //but it has to be visited on the same path
                else if(pathVis[it]){
                    return true;
                }
            }
            pathVis[node]=0; // wapis jaate me pathVis=0 krdo 
            return false;
        }  
    public:
        // Function to detect cycle in a directed graph.
        bool isCyclic(int V, vector<int> adj[]) {
            // code here
            int vis[V]={0};
            int pathVis[V]={0};
            for(int i=0 ; i<V ;i++){
                if(!vis[i]){
                    if(dfs(i , adj , vis , pathVis)==true){
                        return true;
                    }
                }
            }
            return false;
    }
};