import numpy as np
import random

def generate_random_list(length):
    return [random.randint(1, 100) for _ in range(length)]

def main():
    random_list = generate_random_list(24)
    print("Random integer list:", random_list)

    np_array = np.array(random_list)

    reshaped_array = np_array.reshape(6, 4)
    print("Reshaped 6x4 matrix:")
    print(reshaped_array)

    transpose_matrix = reshaped_array.T
    print("Transpose of the matrix:")
    print(transpose_matrix)

main()
