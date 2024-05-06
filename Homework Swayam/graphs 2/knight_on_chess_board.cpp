int knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));  // a visited 
    queue<pair<pair<int,int>,int>>q;
    q.push({{C,D},0});
    vis[C][D]=1;
    int delrow[8]={-2,-1,1,2,2,1,-1,-2};
    int delcol[8]={1,2,2,1,-1,-2,-2,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        if(row==E && col==F){
            return dist;
        }

        //saari directions(8) , new row and col dekh lenge konsa aayega 
        for(int i=0;i<8;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            //row(1-A) //col(1-B)
            if((nrow>=1 && nrow<=A) && (ncol>=1 && ncol<=B) && vis[nrow][ncol]==0){
                q.push({{nrow,ncol},dist+1});
                vis[nrow][ncol]=1;
            }
        } 
    }
    return -1;
}