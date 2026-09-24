class Solution {
public:
    int res(int n){
        int sum=0;
        while(n>0){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0; i<n; i++){
            if(i == res(nums[i])){
                ans = i;
                break;
            }
        }
        return ans;
    }
};