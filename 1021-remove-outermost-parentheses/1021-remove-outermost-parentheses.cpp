class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int d=0;

        for(char c : s){
            if(c=='('){
                d++;
                if(d>1){
                    ans += c;
                }
            }else{
                d--;
                if(d>0){
                    ans += c;
                }
            }
        }
        return ans;
    }
};