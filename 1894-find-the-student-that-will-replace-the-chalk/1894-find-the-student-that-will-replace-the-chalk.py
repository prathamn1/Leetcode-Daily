class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total_chalk=sum(chalk)
        k-=total_chalk*(k//total_chalk)
        for i in range(len(chalk)):
            if k>=chalk[i]:
                k-=chalk[i]
            else:
                return i
            