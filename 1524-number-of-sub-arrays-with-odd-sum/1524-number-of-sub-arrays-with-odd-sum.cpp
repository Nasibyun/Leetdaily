class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        long long even = 1, odd = 0;
        long long ans = 0;
        int mod = 1e9 + 7;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum % 2 != 0) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }
        return ans;
    }
};