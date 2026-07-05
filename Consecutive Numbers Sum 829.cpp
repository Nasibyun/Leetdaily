class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;

        for(long long k=1; k*(k+1)<=2*n; k++){
            long long x=2LL*n + k*(k-1);
            if(x%(2*k)==0 && x>0)ans++;
        }
        return ans;
    }
};
