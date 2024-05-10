#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int> (n,INT_MAX));

        //distance vector bana lo edge se 
		for(auto it:edges) {
			dist[it[0]][it[1]]=it[2];
			dist[it[1]][it[0]]=it[2];
		}

        // [i][i] index pe zero daal do
		for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        //floyd warshall- 3 loops
		for(int k=0;k<n;k++) {
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++) {
					if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX)
						continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		int cntCity=n;
		int cityNo=-1;
		for (int city=0;city<n;city++){
			int cnt=0;
			for (int adj=0; adj<n; adj++){
                //distnce threshold se kam hoga toh valid 
				if(dist[city][adj] <=distanceThreshold)
					cnt++;
			}

			if (cnt<=cntCity) {
				cntCity=cnt;
				cityNo=city;
			}
		}
		return cityNo;
    }
};