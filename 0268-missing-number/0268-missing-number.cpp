class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        int res = 0;

        for(int i=0; i<=nums.size(); i++){
            res ^= i;
        }
        return ans ^ res;
    }
};