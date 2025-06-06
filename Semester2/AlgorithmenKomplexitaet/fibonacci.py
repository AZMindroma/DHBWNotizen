def fibonacci_iterative(amount):
    fibonaccis = [1, 1]

    for i in range(amount-2):
        fibonaccis.append(fibonaccis[i] + fibonaccis[i + 1])

    return fibonaccis

fib_array=[0 for i in range(1000000)]

def fibonacci_recursive_optimized(amount):
    global fib_array

    if amount == 1:
        return 1
    if amount == 2:
        return 1
    elif fib_array[amount] == 0:
        fib_array[amount] = fibonacci_recursive_optimized(amount - 1) + fibonacci_recursive_optimized(amount - 2)

    return fib_array[amount]

def fibonacci_recursive(amount):
    if amount < 3:
        return 1

    #print(fibonacci_recursive(amount - 1) + fibonacci_recursive(amount - 2))

    return fibonacci_recursive(amount-1) + fibonacci_recursive(amount-2)

# print(fibonacci_iterative(50))
#print(fibonacci_recursive(40))
print(fibonacci_recursive_optimized(1000))

