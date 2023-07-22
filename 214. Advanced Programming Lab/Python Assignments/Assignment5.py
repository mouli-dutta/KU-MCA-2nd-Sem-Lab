def find_divisors(n):
    list = []
    for i in range(1, n+1):
        if n % i == 0:
           list.append(i)
    print(list)


def main():
    inp = int(input("Enter a number to find it's divisors: "))
    find_divisors(inp)

main()