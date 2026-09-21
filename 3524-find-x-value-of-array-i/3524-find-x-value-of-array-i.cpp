class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        int dp[2][k];
        memset(dp, 0, sizeof(dp));
        int prev = 0, curr = 1;

        for (int num: nums) {
            num %= k;
            memset(dp[curr], 0, sizeof(dp[curr]));
            dp[curr][num] = 1;
            for (int rem = 0; rem < k; rem++) {
                dp[curr][rem * num % k] += dp[prev][rem];
            }
            for (int rem = 0; rem < k; rem++) {
                res[rem] += dp[curr][rem];
            }
            swap(prev, curr);
        }
        return res;
    }
};