class Solution {
public:
    bool check(vector<int>& nums, int k, int mid) {
        int parts = 1, sum = 0;

        for (int x : nums) {
            if (sum + x > mid) {
                parts++;
                sum = x;
            } else {
                sum += x;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};