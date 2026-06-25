class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0; i<24; i++){ // take 32 cuz there a 32 bits
            int cnt=0;
            for(int a : candidates){
                if((a >> i) & 1){  // right shift with i and then & with 1 if 1 cnt++ else nothing
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
