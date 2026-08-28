class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int> set;
            int sum=0;

            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                set.insert(nums[j]);

                if(set.count(sum)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};