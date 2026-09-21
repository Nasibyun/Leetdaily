class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<int> dp(k, 0);

        for (int num : nums) {
            vector<int> ndp(k, 0);

            int r = num % k;
            ndp[r]++;

            for (int j = 0; j < k; j++) {
                if (dp[j]) {
                    int nr = (j * r) % k;
                    ndp[nr] += dp[j];
                }
            }
            for (int j = 0; j < k; j++)
                ans[j] += ndp[j];
            dp = ndp;
        }

        return ans;
    }
};