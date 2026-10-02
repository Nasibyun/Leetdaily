class Solution:
    def isValid(self, s):
        stack = []
        pairs = {')': '(', ']': '[', '}': '{'}

        for c in s:
            if c in '([{':
                stack.append(c)
            else:
                if not stack or stack.pop() != pairs[c]:
                    return False

        return not stack