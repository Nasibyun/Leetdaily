class Solution {
public:
    int minAddToMakeValid(string s) {
        int del=0, add=0;

        for(char c : s){
            if(c == '('){
                add++;
            }else{
                if(add > 0){
                    add--;
                }else{
                    del++;
                }
            }
        }
        return abs(del+add);
    }
};