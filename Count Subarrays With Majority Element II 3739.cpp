class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0, presum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
};

/* same as Count subarrays with Majority element I 
class Solution {
public:
        long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long n = nums.size(), res = 0, pre = n + 1;
        vector<long long> count(2 * n + 2), acc(2 * n + 2);
        count[pre] = 1, acc[pre] = 1;

        for (int a : nums) {
            pre += (a == target ? 1 : -1);
            count[pre]++;
            acc[pre] = acc[pre - 1] + count[pre];
            res += acc[pre - 1];
        }
        return res;
    }
};
*/
