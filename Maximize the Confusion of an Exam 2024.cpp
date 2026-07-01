class Solution {
public:
    int helper(string &s, int k, char target) {
        int l = 0, cnt=0, ans=0;

        for (int r = 0; r < s.size(); r++) {
            if (s[r] != target)
                cnt++;

            while (cnt > k) {
                if (s[l] != target)
                    cnt--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, k, 'T'),helper(answerKey, k, 'F'));
    }
};
