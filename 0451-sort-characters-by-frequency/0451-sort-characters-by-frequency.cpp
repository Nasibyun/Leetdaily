class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        vector<pair<int,char>> v;
        for(auto [f,s] : mp)
            v.push_back({s,f});

        sort(v.rbegin(), v.rend());

        string ans;

        for(auto [f,s] : v){
            ans += string(f,s);
        }
        return ans;
    }
};