class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> prev(n,0), curr(n,0);
        for(int j=0; j<n; j++) prev[j] = t[n-1][j];

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int d = t[i][j] + prev[j];
                int dg = t[i][j] + prev[j+1];

                curr[j] = min(d, dg);
            }
            prev = curr;
        }
        return prev[0];
    }
};