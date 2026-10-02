class Solution {
public:
    int f(int i, vector<int> a, vector<int>& dp){
        if(i>=a.size()) return 0;
        if(dp[i] != -1)  return dp[i];
        int t = a[i] + f(i+2, a, dp);
        int nt = f(i+1, a, dp);
        return dp[i] = max(t, nt);
    }
    int rob(vector<int>& nums) {

        // memoization
        
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(0, nums, dp);
    }
};