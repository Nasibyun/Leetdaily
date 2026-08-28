class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int pref=0;
        for(int i=0; i<k; i++){
            pref += nums[i];
        }
        double mx = (double)pref/k;

        for(int i=k; i<nums.size(); i++){
            pref += (nums[i]-nums[i-k]);
            double avg = (double)pref/k;
            mx = max(mx, avg);
        }
        return mx;
    }
};