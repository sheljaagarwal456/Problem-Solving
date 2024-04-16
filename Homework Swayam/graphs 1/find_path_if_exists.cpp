#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        unordered_map<int , vector<int>>mp; // map se adjacency list type bana lenge
        for(auto i:edges){  
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        //bfs kiya sarari nodes ke lie
        queue<int>q;
        vis[source]=1;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto it:mp[node]){
                if(!vis[it]){
                    vis[it]=1; // list me agr node visited nhi hai tooooh use visit krke queue me daal dein
                    q.push(it);
                }
            }
        }
        if(vis[destination]==0){ 
            return false;  // traversal ke baad agr destination wali node unvisited reh gyi toh mtlb nhi jaa paaye us node pe to retur false 
        }
        return true;
    }

};