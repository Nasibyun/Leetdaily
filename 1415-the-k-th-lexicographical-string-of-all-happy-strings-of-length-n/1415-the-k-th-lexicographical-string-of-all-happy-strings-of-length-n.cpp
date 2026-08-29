class Solution {
public:
    string ans;
    int count=0;
    void solve(string &s, int n, int k){
        if(s.size() == n){
            count++;
            
            if(count == k){
                ans = s;
            }
            return;
        }

        for(char c='a'; c<='c'; c++){
            if(!s.empty() && s.back()==c){
                continue;
            }

            s.push_back(c);
            solve(s,n,k);
            s.pop_back();

            if(!ans.empty())
                return;
        }
    }
    string getHappyString(int n, int k) {
        string s;
        solve(s,n,k);
        return ans;
    }
};