class Solution {
public:
    bool hasValidPath(vector<vector<char>>& G) {
        int m = G.size(), n = G[0].size();

        if ((m + n - 1) & 1 || (G[0][0] & 1)) {
            return 0;
        }
        vector<bitset<102>> dp(n + 1);
        dp[1].set(0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j + 1] = ((dp[j + 1] | dp[j]) << 1) >> ((G[i][j] & 1) << 1);
            }
        }
        return dp[n].test(0);
    }
};