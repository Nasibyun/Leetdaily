class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();
        int ans = 0;
        long long cover = 0;

        int j=0;

        for (int i = 0; i < n; i++) {
            while (j < n &&
                   tiles[j][1] - tiles[i][0] + 1 <= k) {

                cover += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }

            long long cur = cover;

            if (j<n) {
                int partial = max(0,
                    k - (tiles[j][0] - tiles[i][0]));
                cur += partial;
            }

            ans = max(ans, (int)cur);

            cover -= tiles[i][1] - tiles[i][0] + 1;
        }

        return ans;
    }
};
