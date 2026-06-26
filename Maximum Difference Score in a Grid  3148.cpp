class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int mi = INT_MAX;
                if(i==0 && j==0){
                    continue;
                }
                if(i>0){
                    mi = min(mi,grid[i-1][j]);
                }
                if(j>0){
                    mi = min(mi,grid[i][j-1]);
                }
                ans = max(ans,grid[i][j]-mi);
                
                grid[i][j] = min(mi,grid[i][j]);
            }
        }
        return ans;
    }
};
