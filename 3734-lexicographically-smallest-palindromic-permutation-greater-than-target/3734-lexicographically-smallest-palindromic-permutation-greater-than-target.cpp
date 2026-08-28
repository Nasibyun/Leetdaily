class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        int half = n / 2;
        int have[26];
        for (int i = 0; i < 26; i++)
            have[i] = cnt[i] / 2;

        string left = "";

        for (int i = 0; i < half; i++) {
            int x = target[i] - 'a';

            if (have[x] == 0) {
                left = "";
                break;
            }

            have[x]--;
            left += target[i];
        }

        if (left.size() == half) {
            string right = left;
            reverse(right.begin(), right.end());

            string cur = left;

            if (n % 2)
                cur += mid;

            cur += right;

            if (cur > target)
                return cur;
        }

        for (int i = half - 1; i >= 0; i--) {
            int f[26];

            for (int j = 0; j < 26; j++)
                f[j] = cnt[j] / 2;

            bool ok = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (f[x] == 0) {
                    ok = false;
                    break;
                }

                f[x]--;
            }

            if (!ok)
                continue;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (f[c] == 0)
                    continue;

                f[c]--;

                string L = target.substr(0, i);
                L += char('a' + c);

                for (int x = 0; x < 26; x++) {
                    while (f[x] > 0) {
                        L += char('a' + x);
                        f[x]--;
                    }
                }

                string R = L;
                reverse(R.begin(), R.end());

                string ans = L;

                if (n % 2)
                    ans += mid;

                ans += R;

                return ans;
            }
        }
        return "";
    }
};