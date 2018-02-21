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

        # 数组为空的情况
        if not nums2:
            if not nums1:
                return None

            if len(nums1) % 2 == 0:
                return (nums1[len(nums1) / 2] + nums1[len(nums1) / 2 - 1]) / 2.0
            else:
                return nums1[len(nums1) / 2]

        self.nums1 = nums1
        self.nums2 = nums2
        self.lenth1 = len(nums1)
        self.lenth2 = len(nums2)
        self.side_l = (self.lenth1 + self.lenth2 - 1) / 2

        if not (len(nums1) + len(nums2)) % 2 == 0:
            return self.try_middle(0, len(nums1) - 1, 0)
        else:
            return self.try_middle2()

    def try_middle(self, index1, index2, which):
        i = (index1 + index2) / 2
        if which == 0:

            # 进入首尾的情况
            cond1 = index1 == 0 and index2 == 1 and self.nums1[0] >= self.nums2[self.lenth2 - 1]
            cond2 = index2 == self.lenth1 - 1 and index1 == self.lenth1 - 2 and self.nums1[-1] <= self.nums2[0]
            if cond1:
                return self.nums1[0]
            elif cond2:
                return self.nums1[-1]
            elif index1 == 0 and index2 == 1 or index2 == self.lenth1 - 1 and index1 == self.lenth1 - 2:
                return self.try_middle(0, self.lenth2 - 1, 1)

            # 跳入下一个的情况
            if index2 - index1 == 1:
                return self.try_middle(0, self.lenth2 - 1, 1)

            # out of bound
            if self.side_l - i > self.lenth2:
                return self.try_middle(i, index2, 0)
            if self.side_l - i < 0:
                return self.try_middle(index1, i, 0)

            # get wanted
            # 边缘情况
            if self.side_l - i == self.lenth2:
                if self.nums1[i] >= self.nums2[self.side_l - i - 1]:
                    return self.nums1[i]
                else:
                    return self.try_middle(i, index2, 0)

            elif self.side_l - i == 0:
                if self.nums1[i] <= self.nums2[self.side_l - i]:
                    return self.nums1[i]
                else:
                    return self.try_middle(index1, i, 0)
            elif self.nums2[self.side_l - i - 1] <= self.nums1[i] <= self.nums2[self.side_l - i]:
                return self.nums1[i]

            else:
                if self.nums1[i] >= self.nums2[self.side_l - i]:
                    return self.try_middle(index1, i, 0)
                elif self.nums1[i] <= self.nums2[self.side_l - i - 1]:
                    return self.try_middle(i, index2, 0)

        else:
            # 进入首尾的情况
            if index1 == 0 and index2 == 1:
                if self.nums1[self.side_l - 1] <= self.nums2[0] <= self.nums1[self.side_l]:
                    return self.nums2[0]
                else:
                    return self.nums2[1]

            cond2 = index2 == self.lenth2 - 1 and index1 == self.lenth2 - 2
            if cond2:
                return self.nums2[-1]

            if self.nums1[self.side_l - i - 1] <= self.nums2[i] <= self.nums1[self.side_l - i]:
                return self.nums2[i]
            else:
                if self.nums2[i] >= self.nums1[self.side_l - i]:
                    return self.try_middle(index1, i, 1)
                elif self.nums2[i] <= self.nums1[self.side_l - i - 1]:
                    return self.try_middle(i, index2, 1)

    def try_middle2(self):
        if self.lenth2 == self.lenth1 == 1:
            return (self.nums2[0] + self.nums1[0]) / 2.0
        else:
            # 转换成try_middle1 的情况得出两个中间值
            self.nums1.append(max(self.nums1[-1], self.nums2[-1]) + 1)
            a = self.findMedianSortedArrays(self.nums1, self.nums2)

            self.nums1.pop(-1)
            if self.nums1[-1] > self.nums2[-1]:
                self.nums1.pop(-1)
            else:
                self.nums2.pop(-1)
            b = self.findMedianSortedArrays(self.nums1, self.nums2)
            return (a + b) / 2.0


print Solution().findMedianSortedArrays([1, 3, 4, 5, 11], [2, 6, 8, 9])
print Solution().findMedianSortedArrays([1], [2, 4])
print Solution().findMedianSortedArrays([3], [2, 4])
print Solution().findMedianSortedArrays([1, 1], [1, 1])
print Solution().findMedianSortedArrays([1, 1], [1, 2])
print Solution().findMedianSortedArrays([1, 1], [2, 2])
print Solution().findMedianSortedArrays([1, 2], [1, 2])
print Solution().findMedianSortedArrays([1], [2, 3, 4])
print Solution().findMedianSortedArrays([3], [1, 2, 4])
print Solution().findMedianSortedArrays([3, 5], [2, 4])
print Solution().findMedianSortedArrays([1, 3, 4, 5, 11], [2, 6, 8, 9, 10])
