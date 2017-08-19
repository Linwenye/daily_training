import time

str_ls = ['x']*100000
y = ''
a = time.clock()
x = ''.join(str_ls)
b = time.clock()
print b - a
for i in str_ls:
    y += i
c = time.clock()
print c - b
