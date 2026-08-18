class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for (int x : seen) {
                freq[x]++;
            }
        }
        
        int ans = -1;
        for (auto &[x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};