class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int node=0;node<n;node++){
            vector<int>vis(n,0);
            queue<int>q;
            q.push(node);
            vis[node]=1;
            while(!q.empty()){
                int currnode=q.front();
                q.pop();
                for(auto it:adj[currnode]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                        ans[it].push_back(node);
                    }
                }
            }
        }
        return ans;
    }
};