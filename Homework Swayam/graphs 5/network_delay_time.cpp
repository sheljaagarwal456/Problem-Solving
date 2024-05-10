#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1]; // sabse pehle basic kaam -adjacency list 
    
        for(auto it:times){
            int u=it[0]; //source
            int v=it[1]; //target
            int w=it[2]; //time
            adj[u].push_back({v, w});  // list me uth index pe v aur time daala
        }

        //priority queue usse kara - time aur node
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});

        vector<int> dist(n+1 , INT_MAX);
        dist[k]=0; 

        // Dijkstra 
        while(!pq.empty()){
            int time=pq.top().first; // first wala time hai
            int node=pq.top().second;  // doosra element node hai
            pq.pop();
      
            //list follow krke neighbours ke pass check 
            for(auto i:adj[node]){
                int neighbour=i.first; 
                int w=i.second; 

                //time+w agr kam hai toh update
                if(time + w <dist[neighbour]){
                    dist[neighbour]=time+w;
                    pq.push({dist[neighbour],neighbour });
                }
            }  
        }
        // max element from dist is answer 
        int ans= *max_element(dist.begin()+1 ,dist.end());
        if(ans==INT_MAX){
            return -1; 
        }
        return ans;
    }
};