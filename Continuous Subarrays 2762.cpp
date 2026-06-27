class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long ans = 0;
        deque<int> min, max;
        int r = 0, l = 0;

        for(; r < nums.size(); r++) {
            while(!min.empty() && nums[min.back()] >= nums[r])
                min.pop_back();
            
            min.push_back(r);

            while(!max.empty() && nums[max.back()] <= nums[r])
                max.pop_back();
            
            max.push_back(r);

            while(nums[max.front()] - nums[min.front()] > 2) {
                l++;

                if(!min.empty() && min.front() < l)
                    min.pop_front();
                if(!max.empty() && max.front() < l)
                    max.pop_front();
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
