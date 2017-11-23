import re


def if_statement_test():
    if ' ':
        print 'ok'
    if '':
        print 'no'


def RE_test():
    line = '   fa  b d\n'
    print re.sub(r'\s+', ' ', line)  # this don't change the original parameter
    print line


def python_equal():
    x = 'a'
    list1 = [x, '2']
    list2 = [x, '2']
    list3 = [list1, x]
    list4 = [list2, x]
    print list1 == list2
    print list3 == list4


def str_index():
    strs = 'linwenye'
    print strs[2]


def range_test():
    for i in range(2, 1):
        print 'oh'


if __name__ == '__main__':
    # if_statement_test()
    # RE_test()
    # python_equal()
    str_index()
    range_test()
