class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size();

        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int live=0;

                for(int dr=-1; dr<=1; dr++){
                    for(int dc=-1; dc<=1; dc++){
                        int nr = i+dr;
                        int nc = j+dc;

                        if(dr==0 && dc==0)
                            continue;
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            if(board[nr][nc] == 1){
                                live++;
                            }
                        }
                    }
                }

                if(board[i][j] == 1){
                    if(live==2 || live==3){
                        ans[i][j] = 1;
                    }else{
                        ans[i][j] = 0;
                    }
                }else{
                    if(live==3){
                        ans[i][j] = 1;
                    }else{
                        ans[i][j] = 0;
                    }
                }
            }
        }
        board = ans;
    }
};
