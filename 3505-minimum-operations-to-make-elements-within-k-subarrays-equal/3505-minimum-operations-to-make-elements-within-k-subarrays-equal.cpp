class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.begin());
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };
        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            balance();
        };
        auto remove = [&](int v) {
            auto it = left.find(v);

            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumR -= v;
            }

            balance();
        };
        auto getCost = [&]() -> long long {
            long long m = *left.rbegin();

            return m * left.size() - sumL
                 + sumR - m * right.size();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }
        const long long INF = 4e18;
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }
        return dp[n][k];
    }
};