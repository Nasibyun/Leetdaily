class Solution {
public:
    string s;
    int pos = 0;

    set<string> mergeUnion(set<string> a, set<string> b) {
        for (auto &x : b)
            a.insert(x);
        return a;
    }

    set<string> multiply(set<string> a, set<string> b) {
        set<string> res;

        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            res = mergeUnion(res, parseTerm());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur = parseFactor();
            res = multiply(res, cur);
        }

        return res;
    }

    set<string> parseFactor() {
        if (s[pos] == '{') {
            pos++;
            set<string> res = parseExpression();
            pos++;
            return res;
        }

        string t(1, s[pos]);
        pos++;

        return {t};
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};