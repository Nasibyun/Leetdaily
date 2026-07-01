class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<int>> &dis,vector<vector<int>>& grid,int n){
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<n && dis[nx][ny]>dis[x][y]+1){
                    dis[nx][ny]=1+dis[x][y];
                    q.push({nx,ny});
                }
            }
        }

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        bfs(dis,grid,n);

        priority_queue<pair<int,pair<int,int>>> q;

        vector<vector<int>> best(n,vector<int>(m,-1));
        q.push({dis[0][0],{0,0}});
        best[0][0]=dis[0][0];
        
        while(!q.empty()){
            auto [cs,pos] = q.top();
            q.pop();

            auto [x,y] = pos;

            if(x==n-1 && y==n-1) return cs;

            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];

                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

                int newSafe = min(cs,dis[nx][ny]);

                if(best[nx][ny]<newSafe){
                    best[nx][ny]=newSafe;
                    q.push({newSafe,{nx,ny}});
                }
                
            }
        }
        return 0;
    }
};
