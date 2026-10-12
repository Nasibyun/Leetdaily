class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bits(32, 0);

        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                if (x & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        long long ans = 0;

        while (k--) {
            long long x = 0;
            for (int i = 31; i >= 0; i--) {
                if (bits[i] > 0) {
                    x |= (1LL << i);
                    bits[i]--;
                }
            }
            ans = (ans + x * x) % MOD;
        }
        return ans;
    }
};