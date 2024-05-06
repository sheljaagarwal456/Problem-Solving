class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(vis[j]==0 && isConnected[i][j]==1 ){
                dfs(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};