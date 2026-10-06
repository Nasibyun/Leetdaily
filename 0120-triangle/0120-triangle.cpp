class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> prev = t[n-1];

        for(int i = n-2; i >= 0; i--){
            vector<int> curr(i+1);
            for(int j = 0; j <= i; j++){
                int d = t[i][j] + prev[j];
                int dg = t[i][j] + prev[j+1];

                curr[j] = min(d, dg);
            }
            prev = curr;
        }
        return prev[0];
    }
};