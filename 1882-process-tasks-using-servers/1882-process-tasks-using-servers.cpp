class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P = pair<int, int>;
        using T = tuple<long long, int, int>;

        priority_queue<P, vector<P>, greater<P>> available;
        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
            available.push({servers[i], i});

        for (int i = 0; i < tasks.size(); i++) {

            while (!busy.empty() && get<0>(busy.top()) <= i) {
                auto [time, weight, idx] = busy.top();
                busy.pop();
                available.push({weight, idx});
            }

            if (available.empty()) {
                auto [time, weight, idx] = busy.top();
                busy.pop();

                ans.push_back(idx);
                busy.push({time + tasks[i], weight, idx});
            }
            else {
                auto [weight, idx] = available.top();
                available.pop();

                ans.push_back(idx);
                busy.push({(long long)i + tasks[i], weight, idx});
            }
        }

        return ans;
    }
};