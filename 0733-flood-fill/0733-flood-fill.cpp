class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
        int newColor, int delrow[], int delcol[], int inicolor){

        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == inicolor 
                && ans[nr][nc] != newColor){
                dfs(nr,nc,ans,image,newColor, delrow,delcol,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delrow,delcol,inicolor);
        return ans;
    }
};