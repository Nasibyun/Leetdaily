class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> nums(n);

        long long sum = 1LL * n * (n + 1) / 2;
        if(abs(target) > sum || (sum - target) % 2 == 1) return {};

        long long to_neg = (sum - target) / 2;

        int i = 0;
        int j = n - 1;

        for(int k = n; k >= 1; k--){
            if(to_neg >= k){
                nums[i++] = -k;
                to_neg -= k;
            }
            else{
                nums[j--] = k;
            }
        }
        return nums;
    }
};
