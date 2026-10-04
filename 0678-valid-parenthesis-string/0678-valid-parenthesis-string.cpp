class Solution {
public:
    bool checkValidString(std::string s) {
        int mi = 0,mx = 0;

        for (char c : s) {
            if (c == '(') {
                mi++;
                mx++;
            } else if (c == ')') {
                mi--;
                mx--;
            } else {
                mi--;
                mx++;
            }

            if (mx < 0) {
                return false;
            }
            if (mi < 0) {
                mi = 0;
            }
        }
        return mi == 0;
    }
};