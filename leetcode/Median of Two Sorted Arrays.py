# coding=utf-8
"""
二分搜素得两个排序数组中位数
"""


class Solution(object):
    def __init__(self):
        self.lenth1 = 0
        self.lenth2 = 0
        self.side_l = 0
        self.nums1 = []
        self.nums2 = []

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        if len(nums2) > len(nums1):
            nums1, nums2 = nums2, nums1

        self.nums1 = nums1
        self.nums2 = nums2
        self.lenth1 = len(nums1)
        self.lenth2 = len(nums2)
        self.side_l = (self.lenth1 + self.lenth2 - 1) / 2

        if not (len(nums1) + len(nums2)) / 2 == 0:
            return self.try_middle(0, len(nums1)-1, 0, False)
        else:
            return self.try_middle2(0, len(nums1)-1, 0, False)

    def try_middle(self, index1, index2, which, is_less):
        i = (index1 + index2) / 2
        if which == 0:
            if self.lenth2 < self.lenth1:
                cond1 = index1 == 0 and index2 == 1 and self.nums1[i] > self.nums2[self.lenth2 - 1]
                cond2 = index2 == self.lenth1 - 1 and index1 == self.lenth1 - 2 and self.nums1[i] > self.nums2[0]
                if cond1 or cond2:
                    return self.nums1[i]
                elif index1 == 0 and index2 == 1 or index2 == self.lenth1 - 1 and index1 == self.lenth1 - 2:
                    return self.try_middle(0, self.lenth2, 1, False)

            if self.nums2[self.side_l - i - 1] < self.nums1[i] < self.nums2[self.side_l - i]:
                return self.nums1[i]
            else:
                if self.nums1[i] > self.nums2[self.side_l - i]:
                    return self.try_middle(index1, i, 0, False)
                elif self.nums1[i] < self.nums2[self.side_l - i - 1]:
                    return self.try_middle(i, index2, 0, True)

    def try_middle2(self, index1, index2, which, is_less):
        pass


print Solution().findMedianSortedArrays([1, 3, 7, 10, 11], [2, 6, 8, 9])
