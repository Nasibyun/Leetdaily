class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        vector<int> dp(a+1, 1e9);
        dp[0] = 0;

        for(int i=1; i<=a; i++){
            for(int c : coins){
                if(c <= i){
                    dp[i] = min(dp[i] , 1 + dp[i - c]);
                }
            }
        }
        return dp[a] == 1e9 ? -1 : dp[a];
    }
};