class Solution {
public:
    int dist(vector<vector<int>>&ghosts, vector<int>&target){
        int n=ghosts.size();
        int m=ghosts[0].size();
        int dist=INT_MAX;
        for(int i=0; i<n; i++){
            int ans=0;
            for(int j=0; j<m; j++){
                ans += abs(ghosts[i][j] - target[j]);
            }
            dist = min(dist,ans);
        }
        return dist;
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int mi = abs(target[0]) + abs(target[1]);

        int ghost_d = dist(ghosts,target);
        return mi<ghost_d;
    }
};
