class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        int i = n - 1;
        while (k > 0) {
            int add = min(k, 25);
            ans[i] = 'a' + add;
            k -= add;
            i--;
        }
        return ans;
    }
};