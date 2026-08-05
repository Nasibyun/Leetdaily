class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<int>& vis) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) dfs(v, g, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& ino) {
        vector<vector<int>> g(n);
        for (auto &e : ino)
            g[e[0]].push_back(e[1]);

        vector<int> sus(n, 0);
        dfs(k, g, sus);

        for (auto &e : ino) {
            if (!sus[e[0]] && sus[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!sus[i]) ans.push_back(i);

        return ans;
    }
};