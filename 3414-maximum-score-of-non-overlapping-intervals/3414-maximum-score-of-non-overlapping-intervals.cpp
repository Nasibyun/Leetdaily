class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (intervals[a][0] != intervals[b][0])
                return intervals[a][0] < intervals[b][0];
            return intervals[a][1] < intervals[b][1];
        });

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while (l < r) {
                int mid = (l + r) / 2;

                if (intervals[idx[mid]][0] > intervals[idx[i]][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {
            int id = idx[i];

            for (int k = 1; k <= 4; k++) {
                auto skip = dp[i + 1][k];

                auto take = dp[nxt[i]][k - 1];
                take.first += intervals[id][2];
                take.second.push_back(id);

                sort(take.second.begin(), take.second.end());

                if (take.first > skip.first)
                    dp[i][k] = take;
                else if (take.first < skip.first)
                    dp[i][k] = skip;
                else
                    dp[i][k] = min(take, skip);
            }
        }

        return dp[0][4].second;
    }
};