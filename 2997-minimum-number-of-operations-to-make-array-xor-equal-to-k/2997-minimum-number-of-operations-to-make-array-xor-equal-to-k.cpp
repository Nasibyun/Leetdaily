class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = k;
        for(int num : nums)
            x ^= num;
        return __builtin_popcount(x);
    }
};