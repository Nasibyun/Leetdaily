class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < target.size(); i++) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string cur = target.substr(0, i);
                cur += char('a' + c);

                cnt[c]--;
                for (int j = 0; j < 26; j++) {
                    cur += string(cnt[j], char('a' + j));
                }
                if (ans == "" || cur < ans)
                    ans = cur;
                cnt[c]++;
            }
            int x = target[i] - 'a';

            if (cnt[x] == 0)
                break;
            cnt[x]--;
        }

        return ans;
    }
};