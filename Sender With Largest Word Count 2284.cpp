class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp;

        for (int i = 0; i < messages.size(); i++) {
            int words = 1;
            for (char c : messages[i]) {
                if (c == ' ') words++;
            }
            mp[senders[i]] += words;
        }

        string ans = "";
        int mx = 0;

        for (auto &[sender, cnt] : mp) {
            if (cnt > mx || (cnt == mx && sender > ans)) {
                mx = cnt;
                ans = sender;
            }
        }
        return ans;
    }
};
