class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<int> topo;

    bool check(int mn, vector<bool>& online, long long k) {
        const long long INF = 4e18;

        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto &[v, w] : adj[u]) {

                if (w < mn) continue;

                if (v != n - 1 && v != 0 && !online[v])
                    continue;

                dist[v] = min(dist[v], dist[u] + (long long)w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        n = online.size();
        adj.assign(n, {});
        vector<int> indeg(n, 0);

        int hi = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            hi = max(hi, e[2]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        int lo = 0;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, online, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
