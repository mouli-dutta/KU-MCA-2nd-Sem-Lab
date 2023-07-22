def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)
    
def sumSeries():
    sum = 0
    for i in range(0, 11):
        sum += 1/factorial(i)

        print(f'1/{i}!', end='')
        if i == 10:
            print(" = ", end='')
        else:
            print(" + ", end='')
    
    print(sum)


sumSeries()
    

