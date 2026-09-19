class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>&path){
        vis[node] = 1;
        path[node] = 1;

        for(auto& it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)){
                    return true;
                }
            }else if(path[it]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(auto&p : pre){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(num,0);
        vector<int> path(num,0);
        for(int i=0; i<num; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)){
                    return false;
                }
            }
        }
        return true;
    }
};