class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int max_len = 0;

        if (mp.count(1)) {
            int one = mp[1];
            if (one % 2 == 0) {
                max_len = max(max_len, one-1);
            } else {
                max_len = max(max_len, one);
            }
        }

        for (auto& [val, count] : mp) {
            if (val == 1) continue;

            long long cur = val;
            int len = 0;

            while (mp.count(cur) && mp[cur] >= 2) {
                len += 2;
                cur*=cur;
            }
            if (mp.count(cur) && mp[cur] >= 1) {
                len += 1;
            } else {
                len -= 1; 
            }

            max_len = max(max_len, len);
        }
        return max_len;
    }
};
