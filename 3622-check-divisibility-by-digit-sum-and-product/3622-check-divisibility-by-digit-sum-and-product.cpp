class Solution {
public:
    int res(int n) {
        int sum = 0, pro = 1;
        while (n > 0) {
            int x = n % 10;
            sum += x;
            pro *= x;
            n /= 10;
        }
        return sum + pro;
    }
    bool checkDivisibility(int n) {
        if (n % res(n) == 0) {
            return true;
        } else {
            return false;
        }
    }
};