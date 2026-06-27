class Solution {
public:
    string toLower(string s) {
        for (char &c : s)
            c = tolower(c);
        return s;
    }

    string maskVowel(string s) {
        s = toLower(s);
        for (char &c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '#';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lmp;
        unordered_map<string, string> v_mp;

        for (string word : wordlist) {
            exact.insert(word);

            string low = toLower(word);
            if (!lmp.count(low))
                lmp[low] = word;

            string mask = maskVowel(word);
            if (!v_mp.count(mask))
                v_mp[mask] = word;
        }

        vector<string> ans;

        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
            }
            else if (lmp.count(toLower(q))) {
                ans.push_back(lmp[toLower(q)]);
            }
            else if (v_mp.count(maskVowel(q))) {
                ans.push_back(v_mp[maskVowel(q)]);
            }
            else {
                ans.push_back("");
            }
        }

        return ans;
    }
};
