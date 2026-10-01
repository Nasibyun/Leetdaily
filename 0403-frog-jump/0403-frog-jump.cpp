class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;

        for(int x : stones){
            dp[x] = {};
        }
        dp[0].insert(0);
        
        for(int s : stones){
            for(int x : dp[s]){
                for(int jump = x-1; jump <= x+1; jump++){
                    if(jump <= 0) continue;

                    int pos = s+jump;

                    if(dp.count(pos))
                        dp[pos].insert(jump);
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};