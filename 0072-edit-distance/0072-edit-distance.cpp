class Solution {
public:
    int f(int i, int j, string& w1, string& w2, vector<vector<int>>& dp){
        if(i==0) return dp[i][j] = j;
        if(j==0) return dp[i][j] = i;
        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i-1] == w2[j-1]){
            return dp[i][j] = f(i-1, j-1, w1, w2, dp);
        }
        int insert = f(i-1, j, w1, w2, dp);
        int del = f(i, j-1, w1, w2, dp);
        int replace = f(i-1, j-1, w1, w2, dp);

        return dp[i][j] = 1 + min({insert, del, replace}); 
    }
    int minDistance(string w1, string w2) {
        int i = w1.size(), j = w2.size();
        vector<vector<int>>dp (i+1, vector<int>(j+1, -1));
        return f(i, j, w1, w2, dp);
    }
};