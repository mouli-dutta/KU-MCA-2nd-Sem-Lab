class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)
        print(f"'{item}' pushed into the stack.")

    def pop(self):
        if self.is_empty():
            print("Stack underflow.")
        else:
            item = self.stack.pop()
            print(f"'{item}' poped from the stack.")
            return item

    def is_empty(self):
        return self.stack == []

    def display(self):
        if self.is_empty():
            print("Stack is empty.")
        else:
            print("Stack elements are:")
            for item in reversed(self.stack):
                print(item)


def main():
    stack = Stack()

    while True:
        print("\nMenu:\n")
        print("1. Push")
        print("2. Pop")
        print("3. Display")
        print("4. Exit")

        choice = input("Enter your choice (1/2/3/4): ")

        if choice == "1":
            item = input("Enter the element to push: ")
            stack.push(item)
        elif choice == "2":
            stack.pop()
        elif choice == "3":
            stack.display()
        elif choice == "4":
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please select a valid option (1/2/3/4).")


main()
