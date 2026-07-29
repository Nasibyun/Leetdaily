class Solution {
public:
    static const int LIMIT = 1000005;
    static int comb[5005][5005];
    static bool done;

    static void build() {
        if (done) return;

        for (int i = 0; i <= 5000; i++) {
            comb[i][0] = 1;
            comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                long long val = 1LL * comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] = min((long long)LIMIT, val);
            }
        }

        done = true;
    }

    long long countWays(vector<int> &cnt, int len, int k) {
        long long ans = 1;
        int remain = len;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;

            ans *= comb[remain][cnt[i]];
            if (ans >= LIMIT || ans > k)
                return LIMIT;

            remain -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        build();

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int oddCnt = 0;
        char middle = '#';
        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                oddCnt++;
                middle = char('a' + i);
            }

            freq[i] /= 2;
            halfLen += freq[i];
        }

        if (oddCnt > 1)
            return "";

        if (countWays(freq, halfLen, k) < k)
            return "";

        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (freq[ch] == 0)
                    continue;

                freq[ch]--;

                long long ways = countWays(freq, halfLen - pos - 1, k);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                }

                k -= ways;
                freq[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (oddCnt)
            return left + string(1, middle) + right;

        return left + right;
    }
};

int Solution::comb[5005][5005];
bool Solution::done = false;