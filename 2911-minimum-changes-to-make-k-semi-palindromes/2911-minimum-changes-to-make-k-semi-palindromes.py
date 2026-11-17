class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = float('inf')

        cost = [[INF] * n for _ in range(n)]

        for i in range(n):
            for j in range(i + 1, n):
                length = j - i + 1

                for d in range(1, length):
                    if length % d:
                        continue

                    cnt = 0
                    m = length // d

                    for r in range(d):
                        for t in range(m // 2):
                            x = r + t * d
                            y = r + (m - 1 - t) * d

                            if s[i + x] != s[i + y]:
                                cnt += 1

                    cost[i][j] = min(cost[i][j], cnt)

        dp = [[INF] * (n + 1) for _ in range(k + 1)]
        dp[0][0] = 0

        for p in range(1, k + 1):
            for i in range(2 * p, n + 1):
                for j in range(2 * (p - 1), i - 1):
                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    )

        return dp[k][n]