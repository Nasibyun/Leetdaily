class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
        int newColor, int inicolor){

        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == inicolor 
                && ans[nr][nc] != newColor){
                dfs(nr,nc,ans,image,newColor,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,ans,image,color,inicolor);
        return ans;
    }
};