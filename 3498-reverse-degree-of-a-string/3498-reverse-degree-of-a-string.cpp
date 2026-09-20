class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int extra = 26;
        for(int i=0; i<s.size(); i++){
            sum += (i+1)*(extra - (s[i] - 'a'));
        }
        return sum;
    }
};