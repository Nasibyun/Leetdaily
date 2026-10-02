class Solution {
public:
    int f(vector<int>& nums){
        int n = nums.size();
        int curr=0, pr =0, npr =0;
        for(int i=0; i<n; i++){
            int t = nums[i] + npr;
            int nt = pr;

            curr = max(t, nt);
            npr = pr;
            pr = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n == 1)  return nums[0];
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(f(temp1) , f(temp2));
    }
};