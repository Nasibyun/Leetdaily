class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;

        result += max(0LL, n - 999LL);
        result += max(0LL, n - 999999LL);
        result += max(0LL, n - 999999999LL);
        result += max(0LL, n - 999999999999LL);
        result += max(0LL, n - 999999999999999LL);

        return result;
    }
};