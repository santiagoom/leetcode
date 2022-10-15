from typing import List
from utils import *


class Solution_040_CombinationSumII_2:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        def backtrack(comb, remain, curr, results):

            if remain == 0:
                # make a deep copy of the resulted combination
                results.append(list(comb))
                return

            for next_curr in range(curr, len(candidates)):

                if next_curr > curr \
                        and candidates[next_curr] == candidates[next_curr - 1]:
                    continue

                pick = candidates[next_curr]
                # optimization: skip the rest of elements starting from 'curr' index
                if remain - pick < 0:
                    break

                comb.append(pick)
                backtrack(comb, remain - pick, next_curr + 1, results)
                comb.pop()

        candidates.sort()

        comb, results = [], []
        backtrack(comb, target, 0, results)

        return results


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
