def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

def main():
    inp = int(input("Enter a number to find it's factorial: "))
    print(f'{inp}! = {factorial(inp)}')

main()