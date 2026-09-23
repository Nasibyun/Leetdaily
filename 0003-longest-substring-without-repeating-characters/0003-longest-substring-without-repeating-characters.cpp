class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int l=0, length=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[l]]--;
                l++;
            }
            length = max(length, i-l+1);
        }
        return length;
    }
};