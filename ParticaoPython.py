def partitions(A):
    if not A:
        yield []
    else:
        a, *R = A
        for partition in partitions(R):
            yield partition + [[a]]
            for i, subset in enumerate(partition):
                yield partition[:i] + [subset + [a]] + partition[i+1:]

for partition in partitions({1,2,3,4}):
    print(partition)

