class Solution {
public:
    long long minimumCost(int c1, int c2, int cc, int n1, int n2) {
        long long ans = 1e18;

        ans = min(ans, 1LL*c1*n1 + 1LL*c2*n2);
        ans = min(ans, 1LL*min(n1,n2)*cc + ((n1 > n2) ? 1LL*(n1-n2)*c1 : 1LL*(n2-n1)*c2));
        ans = min(ans, 1LL*cc*max(n1,n2));
        return ans;
    }
};