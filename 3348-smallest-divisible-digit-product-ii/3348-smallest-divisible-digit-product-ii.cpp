class Solution {
public:
    vector<vector<int>> fact = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    vector<int> getFactors(long long t) {
        vector<int> cnt(4, 0);
        int p[] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % p[i] == 0) {
                t /= p[i];
                cnt[i]++;
            }
        }

        if (t != 1) return {};
        return cnt;
    }

    vector<int> getDigits(vector<int> c) {
        vector<int> res(10, 0);

        res[8] = c[0] / 3;
        c[0] %= 3;

        res[9] = c[1] / 2;
        c[1] %= 2;

        res[4] = c[0] / 2;
        c[0] %= 2;

        res[2] = c[0];
        res[3] = c[1];

        if (res[2] && res[3]) {
            res[2] = 0;
            res[3] = 0;
            res[6] = 1;
        }

        if (res[3] && res[4]) {
            res[3] = 0;
            res[4] = 0;
            res[2] = 1;
            res[6] = 1;
        }

        res[5] = c[2];
        res[7] = c[3];

        return res;
    }

    int countDigits(vector<int> c) {
        vector<int> d = getDigits(c);
        int res = 0;

        for (int i = 2; i <= 9; i++)
            res += d[i];

        return res;
    }

    string build(vector<int> c) {
        vector<int> d = getDigits(c);
        string res;

        for (int i = 2; i <= 9; i++)
            res += string(d[i], char('0' + i));

        return res;
    }

    string smallestNumber(string num, long long t) {
        int n = num.size();

        vector<int> target = getFactors(t);

        if (target.empty() && t != 1)
            return "-1";

        if (countDigits(target) > n)
            return build(target);

        vector<int> prefix(4, 0);

        for (char ch : num) {
            int d = ch - '0';

            for (int j = 0; j < 4; j++)
                prefix[j] += fact[d][j];
        }

        int firstZero = -1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        // num itself is already valid
        if (firstZero == -1) {
            bool ok = true;

            for (int j = 0; j < 4; j++) {
                if (prefix[j] < target[j])
                    ok = false;
            }

            if (ok)
                return num;

            firstZero = n;
        }

        // Try changing one position from right to left
        for (int i = n - 1; i >= 0; i--) {
            int d = num[i] - '0';

            for (int j = 0; j < 4; j++)
                prefix[j] -= fact[d][j];

            if (i > firstZero)
                continue;

            int space = n - i - 1;

            for (int bigger = d + 1; bigger <= 9; bigger++) {
                vector<int> need(4);

                for (int j = 0; j < 4; j++) {
                    need[j] = max(
                        0,
                        target[j] - prefix[j] - fact[bigger][j]
                    );
                }

                int required = countDigits(need);

                if (required <= space) {
                    string ans = num.substr(0, i);
                    ans += char('0' + bigger);

                    ans += string(space - required, '1');
                    ans += build(need);

                    return ans;
                }
            }
        }
        int required = countDigits(target);

        return string(n + 1 - required, '1') + build(target);
    }
};