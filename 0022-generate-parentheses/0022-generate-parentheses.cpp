class Solution {
public:
    void solve(int i, int j, string s, vector<string>& ans){
        if(i==0 && j==0){
            ans.push_back(s);
            return;
        }

        if(i>0) solve(i-1, j, s+'(', ans);
        if(j>i) solve(i, j-1, s+')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,"", ans);
        return ans;
    }
};