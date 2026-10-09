class Solution:
    def minInsertions(self, s: str) -> int:
        s = s.replace("))", "}")
        req = 0
        miss = 0

        for bracket in s:
            if bracket == "(":
                req += 2
            else:
                if bracket == ")":
                    miss += 1
                if req:
                    req -= 2
                else:
                    miss += 1
        
        return miss + req