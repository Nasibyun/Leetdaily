class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int extra = accumulate(nums.begin(), nums.end(),0);
        int target = extra - x;

        if(target == x) return nums.size();
        if(target <= -1) return -1;
        int sum=0;
        int j=0, res=-1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            while(target < sum && j <= i){
                sum -= nums[j];
                j++;
            }

            if(target == sum){
                res = max(res, i-j+1);
            }
        }
        return res == -1 ? -1 : nums.size() - res;
    }
};