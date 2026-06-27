class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int mx=0, cnt=0;

        while(j<s.size()){
            if(isVowel(s[j]))
                cnt++;

            if(j-i+1 == k){
                mx = max(mx,cnt);
                if(isVowel(s[i]))
                    cnt--;
                i++;
            }
            j++;
        }
        return mx;
    }
};
