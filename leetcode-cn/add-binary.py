#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        aa = int(a, 2)
        bb = int(b, 2)
        ans = aa + bb
        return bin(ans)[2:]
# @lc code=end

