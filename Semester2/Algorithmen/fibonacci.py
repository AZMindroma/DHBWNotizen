def fibonacci_iterative(amount):
    fibonaccis = [1, 1]

    for i in range(amount-2):
        fibonaccis.append(fibonaccis[i] + fibonaccis[i + 1])

    return fibonaccis

def fibonacci_recursive(amount):
    if amount < 3:
        return 1

    #print(fibonacci_recursive(amount - 1) + fibonacci_recursive(amount - 2))

    return fibonacci_recursive(amount-1) + fibonacci_recursive(amount-2)

# print(fibonacci_iterative(50))
print(fibonacci_recursive(40))


