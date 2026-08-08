class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        total = sum(i for i in range(1, maxChoosableInteger+1))
        if total < desiredTotal:
            return False
        if desiredTotal <= 0:
            return True

        def dp(used, curr, memo: dict):
            if curr <= 0:
                return False
            if used not in memo:
                for i in range(1, maxChoosableInteger+1):
                    if not (used & (1 << (i - 1))):
                        if i >= curr:
                            memo[used] = True
                            return True
                        else:
                            if not dp(used | (1 << (i - 1)), curr - i, memo):
                                memo[used] = True
                                return True
                            else:
                                memo[used] = False
            return memo[used]
        return dp(0, desiredTotal, {})