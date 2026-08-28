class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=-1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] - nums[i] != 1)
                continue;
            
            int len=2;
            ans = max(ans , len);

            for(int j=i+2; j<nums.size(); j++){
                if(nums[j-2] == nums[j]){
                    len++;
                    ans = max(ans,len);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};