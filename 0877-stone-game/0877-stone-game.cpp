class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum1 = 0, sum2=0;

        int i = 0, j = n-1;

        while(i<j){
            sum1 += max(piles[i],piles[j]);
            sum2 += min(piles[i],piles[j]);
            i++,j--;
        }
        return (sum1 > sum2);
    }
};