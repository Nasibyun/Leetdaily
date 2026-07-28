class Solution {
public:
    int solve(vector<int>&nums, int f, int s){
        int n=nums.size();
        vector<int> pref(n+1,0);

        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + nums[i];
        }

        int sum=0, ans=0;
        for(int i=f+s; i<=n; i++){
            sum = max(sum, pref[i-s] - pref[i-s-f]);
            int s1 = pref[i] - pref[i-s];
            ans = max(ans, sum + s1);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        return max(solve(nums,f,s), solve(nums,s,f));
    }
};