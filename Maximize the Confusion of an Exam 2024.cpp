class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        vector<int> freq(26, 0);

        int l = 0,cnt = 0,ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            cnt = max(cnt, freq[s[r] - 'A']);

            while ((r - l + 1) - cnt > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
