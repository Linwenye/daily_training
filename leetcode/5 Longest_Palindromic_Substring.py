# coding=utf-8
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        longest = 1
        res = s[0]
        # 中心对称 aba型
        lenth = len(s)
        for i, middle in enumerate(s):
            if i == 0 or i == lenth:
                continue
            j = 1
            tem = 1
            while 1:
                if j <= i and j <= lenth - i - 1 and s[i - j] == s[i + j]:
                    tem += 2
                    j += 1
                else:
                    if tem > longest:
                        longest = tem
                        res = s[i - j + 1:i + j]
                    break

        # abba 型
        longtem = 0
        res2 = None
        for i, middle in enumerate(s):
            tem2 = 0
            j = 0
            while 1:
                if j <= i and j <= lenth - i - 2 and s[i - j] == s[i + j + 1]:
                    tem2 += 2
                    j += 1
                else:
                    if tem2 > longtem:
                        longtem = tem2
                        res2 = s[i - j + 1:i + j + 1]
                    break
        if longtem > longest:
            return res2
        else:
            return res


# print Solution().longestPalindrome('babad')
# print Solution().longestPalindrome('cbbd')
# print Solution().longestPalindrome('acbbcad')
