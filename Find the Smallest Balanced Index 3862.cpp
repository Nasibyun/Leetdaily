class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n= nums.size();
        long long sum=0, prod=1;

        for(int num : nums){
            sum += num;
        }

        for(int i=n-1; i>=0; i--){
            sum -= nums[i];
            if(sum == prod){
                return i;
            }
            if(nums[i] > sum/prod){
                break;
            }
            prod*=nums[i];
        }
        return -1;
    }
};
