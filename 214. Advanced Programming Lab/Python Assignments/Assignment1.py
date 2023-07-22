class Account:
    def __init__(self, account_number, date_of_opening, customer_name, initial_balance=0):
        self.account_number = account_number
        self.date_of_opening = date_of_opening
        self.customer_name = customer_name
        self.balance = initial_balance
        self.transaction_history = []

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transaction_history.append(f"Deposited: ${amount}")
            print(f"Deposit of ${amount} successful. New balance: ${self.balance}")
        else:
            print("Invalid deposit amount. Please enter a positive number.")

    def withdraw(self, amount):
        if amount > 0:
            if self.balance >= amount:
                self.balance -= amount
                self.transaction_history.append(f"Withdrew: ${amount}")
                print(f"Withdrawal of ${amount} successful. New balance: ${self.balance}")
            else:
                print("Insufficient funds.")
        else:
            print("Invalid withdrawal amount. Please enter a positive number.")

    def check_balance(self):
        print(f"Account balance: ${self.balance}")

    def account_history(self):
        if self.transaction_history:
            print("Transaction history:")
            for transaction in self.transaction_history:
                print(transaction)
        else:
            print("No transaction history for this account.")


def main():
    print("Welcome to the Banking Site!")
    account_number = input("Enter your account number: ")
    date_of_opening = input("Enter the date of opening (YYYY-MM-DD): ")
    customer_name = input("Enter your name: ")

    account = Account(account_number, date_of_opening, customer_name)

    while True:
        print("\nChoose an option:")
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Check Balance")
        print("4. Account History")
        print("5. Exit")

        choice = input("Enter the number corresponding to your choice: ")

        if choice == "1":
            amount = float(input("Enter the amount to deposit: "))
            account.deposit(amount)
        elif choice == "2":
            amount = float(input("Enter the amount to withdraw: "))
            account.withdraw(amount)
        elif choice == "3":
            account.check_balance()
        elif choice == "4":
            account.account_history()
        elif choice == "5":
            print("Thank you for using the Banking Site. Goodbye!")
            break
        else:
            print("Invalid choice. Please choose a valid option.")


main()
