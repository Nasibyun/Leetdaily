class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int sum = 0, ans = INT_MAX;
        int best = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (mp.count(sum - target)) {
                int l = mp[sum - target] + 1;
                int len = i - mp[sum - target];
                
                if (l > 0 && dp[l - 1] != INT_MAX)
                    ans = min(ans, len + dp[l - 1]);
                
                best = min(best, len);
            }
            
            dp[i] = best;
            mp[sum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};