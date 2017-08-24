class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 1
        lenth = len(nums) - 1
        present_i = 0
        if lenth == 0:
            return 0
        while present_i < lenth:
            tem_max = 0
            next_i = 0
            if present_i + nums[present_i] >= lenth:
                return res
            for index_now, pp in enumerate(nums[present_i + 1:present_i + nums[present_i] + 1]):
                index_now += present_i + 1
                if index_now == lenth:
                    return res
                if pp + index_now > tem_max:
                    next_i = index_now
                    tem_max = pp + index_now
            present_i = next_i
            res += 1
        return res


print Solution().jump([2, 3, 1, 1, 4])
print Solution().jump([0])
print Solution().jump([1, 1, 1])
