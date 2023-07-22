class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)
        print(f"{item} enqueued successfully.")

    def dequeue(self):
        if not self.is_empty():
            item = self.queue.pop(0)
            print(f"{item} dequeued successfully.")
        else:
            print("Queue underflow")

    def display(self):
        if not self.is_empty():
            print("Queue elements:")
            for item in self.queue:
                print(item)
        else:
            print("Queue is empty.")

    def is_empty(self):
        return len(self.queue) == 0


def main():
    queue = Queue()

    while True:
        print("\nChoose an option:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")

        choice = input("Enter your choice (1/2/3/4): ")

        if choice == "1":
            item = input("Enter the item to enqueue: ")
            queue.enqueue(item)
        elif choice == "2":
            queue.dequeue()
        elif choice == "3":
            queue.display()
        elif choice == "4":
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please select a valid option (1/2/3/4).")


main()
