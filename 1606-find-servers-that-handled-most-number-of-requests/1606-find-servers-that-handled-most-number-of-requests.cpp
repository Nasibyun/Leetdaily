class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> cnt(k, 0);

        for(int i = 0; i < arrival.size(); i++) {
            int t = arrival[i];

            while(!busy.empty() && busy.top().first <= t) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) continue;
            auto it = available.lower_bound(i % k);

            if(it == available.end()) it = available.begin();
            int server = *it;

            available.erase(it);
            cnt[server]++;
            busy.push({t + load[i], server});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};