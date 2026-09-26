class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int l=0, r=height.size()-1;
        int lmx=0, rmx=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] >= lmx){
                    lmx = height[l];
                }else{
                    sum += (lmx - height[l]);
                }
                l++;
            }else{
                if(height[r] >= rmx){
                    rmx = height[r];
                }else{
                    sum += (rmx - height[r]);
                }
                r--;
            }
        }
        return sum;
    }
};