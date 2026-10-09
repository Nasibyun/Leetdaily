class Solution:
    def minInsertions(self, s: str) -> int:
        ans = 0
        open = 0
        n = len(s)
        i = 0

        while i < n:
            if s[i] == '(':
                open += 1
            else:
                if i+1 < n and s[i+1] == ')':
                    i+=1
                else:
                    ans+=1

                if open==0:
                    ans+=1
                else:
                    open-=1

            i+=1

        ans += 2*open
        return ans