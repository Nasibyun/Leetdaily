class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    
    bool solve(vector<vector<char>>& grid, int i, int j, int bal) {
        if (bal < 0) return false;
        if (bal > n + m) return false;
        
        if (i == n - 1 && j == m - 1)
            return bal == 0 && grid[i][j] == ')';
        
        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];
        
        bool ans = false;
        
        if (i + 1 < n) {
            int nb = bal + (grid[i + 1][j] == '(' ? 1 : -1);
            ans |= solve(grid, i + 1, j, nb);
        }
        
        if (j + 1 < m) {
            int nb = bal + (grid[i][j + 1] == '(' ? 1 : -1);
            ans |= solve(grid, i, j + 1, nb);
        }
        
        return dp[i][j][bal] = ans;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        if (grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;
        
        if ((n + m - 1) % 2)
            return false;
        
        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
        return solve(grid, 0, 0, 1);
    }
};