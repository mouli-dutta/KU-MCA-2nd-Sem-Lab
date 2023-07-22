def is_prime(n):
    if n < 2:
        return False
    
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def find_primes(n):
    list = []
    for i in range(1, n+1):
        if is_prime(i):
            list.append(i)
    print(list)


def main():
    inp = int(input("Enter a number to find all the prime numbers upto it: "))
    find_primes(inp)

main()
