import time

list1 = [1, 4] * 100000
list2 = [2, 3] * 10000
time_a = time.clock()
l3 = list1 + list2
print time.clock()-time_a
