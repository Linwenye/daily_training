def return_in_for():
    for i in range(5):
        yield i


generator = return_in_for()
for t in generator:
    print(t)
for t in generator:
    print(t)
