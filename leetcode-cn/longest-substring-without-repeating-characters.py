class Solution:
    def lengthOfLongestSubstring(self, s):
        left = 0
        right = 0
        maxNum = 0
        curNum = 0

        while right < len(s):
            if (s[right] not in s[left:right]):
                right+=1

                curNum = right - left
                maxNum = max(maxNum,curNum)
                continue
            else:
                left+=1
                right = left + 1
        return maxNum

    def lengthOfLongestSubstringOpt(self, s):
        from collections import defaultdict
        lookup = defaultdict(int)
        start = 0
        end = 0
        max_len = 0
        counter = 0
        while end < len(s):
            if lookup[s[end]] > 0:
                counter += 1
            lookup[s[end]] += 1
            end += 1
            while counter > 0:
                if lookup[s[start]] > 1:
                    counter -= 1
                lookup[s[start]] -= 1
                start += 1
            max_len = max(max_len, end - start)
        return max_len





if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthOfLongestSubstring("abcabc"))
    pass
