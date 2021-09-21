def factorial(number):
    if number <= 1:
        return 1
    return number * factorial(number - 1)


N, M = map(int, input().split())
denominator = factorial(M) * factorial(N - M)
numerator = factorial(N)

print(numerator // denominator)