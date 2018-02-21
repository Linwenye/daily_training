def pointer_test():
    list1 = []
    list2 = []
    a = [1, 2, 3]
    list1.append(a)

    tt = list1[0]
    list2.append(tt)
    a.remove(1)
    print list2
    print list1


def object_in_list():
    list1 = []

    class A:
        def __init__(self, s):
            self.ss = s

    a = A(0)
    list1.append(a)
    b = A(0)
    print b in list1


object_in_list()