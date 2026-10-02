class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation

        int n = nums.size();
        // vector<int> dp(n+2, 0);
        int curr=0, pr =0, mpr =0;
        for(int i=n-1; i>=0; i--){
            int t = nums[i] + mpr;
            int nt = pr;
            curr = max(t, nt);
            mpr = pr;
            pr = curr;
        }
        return pr;
    }
};