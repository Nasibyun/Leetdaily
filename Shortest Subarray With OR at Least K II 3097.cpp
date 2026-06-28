class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if(nums[i]>=k) return 1;
            for (int j = i-1; j>=0; j--) {
                if((nums[j] | nums[i]) == nums[j])
                    break;
                nums[j] |= nums[i];
                if(nums[j] >= k){
                    ans = min(ans, i-j+1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
