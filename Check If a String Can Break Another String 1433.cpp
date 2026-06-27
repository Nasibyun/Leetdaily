// Means every charater of s1 is either (lesser or equal) or (greater or equal) so true else false

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i=0,j=0;
        bool st1=true, st2=true;

        for(int i=0; i<s1.size(); i++){
            if(s1[i] < s2[i]){
                st1 = false;
            }  
            if(s1[i] > s2[i]){
                st2 = false;
            }
        }
        return st1 || st2;
    }
};
