class ProductOfNumbers:
    def __init__(self):
        self.ans = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.ans = [1]
        else:
            self.ans.append(self.ans[-1] * num)

    def getProduct(self, k: int) -> int:
        n = len(self.ans)
        if k >= n:
            return 0

        return self.ans[-1] // self.ans[n-k-1]
