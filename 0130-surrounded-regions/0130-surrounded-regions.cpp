class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col] = 1;

        int n=board.size();
        int m=board[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,vis);
            }

            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis);
            }
        }

        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,board,vis);
            }

            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};