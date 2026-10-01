class Solution(object):
    def canCross(self, stones):
        n = len(stones)
        dp = {s : set() for s in stones}
        dp[0].add(0)

        for s in stones:
            for k in dp[s]:
                for jump in (k-1, k , k+1):
                    if jump > 0 and s+jump in dp:
                        dp[s + jump].add(jump)
        
        return bool(dp[stones[-1]])
        