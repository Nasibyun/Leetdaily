class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        int miIdx=0, mxIdx=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == mi)
                miIdx = i;
            
            if(nums[i] == mx)
                mxIdx = i;
            
        }
        if (miIdx > mxIdx)
            swap(miIdx, mxIdx);

        int front = mxIdx+1;
        int back = nums.size() - miIdx;
        int both = miIdx + 1 + nums.size() - mxIdx;

        return min({front,back,both});
    }
};