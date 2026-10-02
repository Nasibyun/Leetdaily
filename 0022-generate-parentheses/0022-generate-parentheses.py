class Solution(object):
    def generateParenthesis(self, n):
        ans= []

        def solve(i,j,s):
            if i==0 and j==0:
                ans.append(s)
                return
            
            if i>0:
                solve(i-1,j,s+'(')
            if j>i:
                solve(i,j-1,s+')')
        
        solve(n,n,"")
        return ans

        