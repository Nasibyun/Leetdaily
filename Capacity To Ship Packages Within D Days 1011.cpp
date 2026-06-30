class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int curr = 0;
        int need = 1;

        for (int w : weights) {
            if (curr + w > cap) {
                need++;
                curr = 0;
            }
            curr += w;
        }
        return need <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
