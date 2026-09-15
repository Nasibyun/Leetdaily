class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int tm=0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            tm = max(tm,time);
            q.pop();

            for(int i=0; i<4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && vis[nr][nc] == 0){
                    q.push({{nr,nc}, time + 1});
                    vis[nr][nc] = 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
    }
};