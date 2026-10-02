class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation

        int n = nums.size();
        vector<int> dp(n+2, 0);
        for(int i=n-1; i>=0; i--){
            int t = nums[i] + dp[i+2];
            int nt = dp[i+1];
            dp[i] = max(t,nt);
        }
        return dp[0];
    }
};