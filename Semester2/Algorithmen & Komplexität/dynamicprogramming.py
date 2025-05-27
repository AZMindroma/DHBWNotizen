def down_to_one(value):
    if value == 1:
        return 1
    else:
        subcost = down_to_one(value - 1)
        rule = 1
        if value % 2 == 0:
            tmp = down_to_one(value / 2)
            if tmp < subcost:
                subcost = tmp
                rule = 2
        if value % 3 == 0:
            tmp = down_to_one(value / 3)
            if tmp < subcost:
                subcost = tmp
                rule = 3
        cost = subcost + 1
        return cost

print(down_to_one(100))

def greedy(value):
    if value == 1:
        return 1
    else:
        if value % 3 == 0:
            value = value // 3
        elif value % 2 == 0:
            value = value // 2
        else:
            value = value - 1

        return greedy(value)

print(greedy(100))