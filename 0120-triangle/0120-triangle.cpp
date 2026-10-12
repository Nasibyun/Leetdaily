class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp) {
    //     int n = t.size();
    //     if (i == n-1) return t[i][j];
    //     if (dp[i][j] != -1) return dp[i][j];

    //     int down = t[i][j] + solve(i+1, j, t, dp);
    //     int diagonal = t[i][j] + solve(i+1, j+1, t, dp);

    //     return dp[i][j] = min(down, diagonal);
    // }
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j=0; j<n; j++) dp[n-1][j] = t[n-1][j];

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int d = dp[i+1][j];
                int dg = dp[i+1][j+1];

                dp[i][j] = min(d,dg) + t[i][j];
            }
        }
        return dp[0][0];
    }
};