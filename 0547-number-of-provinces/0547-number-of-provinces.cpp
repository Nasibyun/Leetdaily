class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                cnt++;

                while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            }
        }
            
        return cnt;
    }
};