using ll = long long;
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> dp(26,0);
        const int MOD = 1e9+7;
        ll ttl=0;

        for(char c : s){
            ll x = c-'a';
            ll add = (ttl + 1)%MOD;
            ttl = (ttl + add - dp[x] + MOD) % MOD;

            dp[x] = add;
        }
        return ttl;
    }
};