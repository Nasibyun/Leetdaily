class Solution {
public:
    int f(int n1, int n2, string& t1, string& t2, vector<vector<int>>& dp){
        if(n1 == 0 || n2 == 0) return dp[n1][n2] = 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(t1[n1-1] == t2[n2-1]){
            return dp[n1][n2] = 1 + f(n1-1, n2-1, t1, t2, dp);
        }

        int s1 = f(n1-1, n2, t1, t2, dp);
        int s2 = f(n1, n2-1, t1, t2, dp);

        return dp[n1][n2] = max(s1, s2);
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size(), n2 = t2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));

        return f(n1, n2, t1, t2, dp);
    }
};