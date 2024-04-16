#include<bits/stdc++.h>
using namespace std;
class Solution {
 private:
    void bfs(int row, int col, vector<vector<int>>&vis , vector<vector<char>>&grid , int delrow[], int delcol[]){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            
            //traverse in the neighbours and mark them if its a land 
            
                for(int i=0;i<4;i++){
                    int nextrow=row+delrow[i];
                    int nextcol=col+delcol[i];
                    if(nextrow>=0 && nextrow<n && nextcol>=0 && nextcol<m
                    && grid[nextrow][nextcol]=='1' && !vis[nextrow][nextcol]){
                        vis[nextrow][nextcol]=1;
                        q.push({nextrow , nextcol});
                    }
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0 ; row<n ; row++){
            for(int col=0 ; col<m ; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count=count+1;
                    bfs(row,col,vis,grid,delrow,delcol);
                }
            }
        }
        return count;
    }
};