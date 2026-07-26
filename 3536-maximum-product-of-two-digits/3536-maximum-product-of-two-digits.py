class Solution:
    def maxProduct(self, n: int) -> int:
        s = str(n)
        max1 = 0
        max2 = 0
        for c in s:
            d = int(c)
            if d > max1:
                max2 = max1
                max1 = d
            elif d > max2:
                max2 = d
        return max1 * max2