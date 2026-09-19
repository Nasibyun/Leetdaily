class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        if(vis[node] == 1){
            return true;
        }
        if(vis[node] == 2){
            return false;
        }

        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(dfs(adj[node][i],adj,vis)){
                return true;
            }
        }

        vis[node] = 2;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(auto&p : pre){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(num,0);
        for(int i=0; i<num; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis)){
                    return false;
                }
            }
        }
        return true;
    }
};