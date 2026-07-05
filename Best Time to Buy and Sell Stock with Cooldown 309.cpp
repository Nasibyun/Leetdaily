class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -1e9, sold = 0, rest = 0;
        
        for (int p : prices) {
            int prev_sold = sold;
            
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prev_sold);
        }
        
        return max(rest, sold);
    }
};
