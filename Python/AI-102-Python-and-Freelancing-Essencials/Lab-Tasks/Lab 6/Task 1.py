class Wallet:
    def __init__(self, balance):
        self.__balance = balance   # Encapsulated attribute to store initial funds

    def add_money(self, money):
        # Validates and credits the specified amount to the wallet
        if money <= 0:
            print("[!] Error: Invalid deposit amount.")
        else:
            self.__balance += money
            print(f"[+] Success: ${money} deposited.")

    def spend_money(self, money):
        # Debits the wallet if sufficient funds are available
        if money <= 0:
            print("[!] Error: Invalid expenditure amount.")
        elif money > self.__balance:
            print("[!] Error: Insufficient funds for this transaction.")
        else:
            self.__balance -= money
            print(f"[-] Success: ${money} spent.")

    def transfer(self, other, amount):
        # Handles peer-to-peer transfers between wallet instances
        if amount <= 0:
            print("[!] Error: Invalid transfer amount.")
        elif amount > self.__balance:
            print("[!] Error: Insufficient funds to complete transfer.")
        else:
            self.__balance -= amount
            other.__balance += amount
            print(f"[>] Success: ${amount} transferred to the receiving wallet.")

    def show_balance(self):
        # Displays the formatted account balance
        print(f"    Available Balance: ${self.__balance}")


# Instantiate dual wallet objects
w1 = Wallet(0)
w2 = Wallet(0)

# Application Main Loop
while True:
    print("MAIN MENU:")
    print("  [1] Add Funds")
    print("  [2] Spend Funds")
    print("  [3] Transfer Funds")
    print("  [4] View Balances")
    print("  [5] Exit Application")
    print()

    choice = int(input("Select an option (1-5): "))

    if choice == 1:
        # Route deposit to the requested wallet instance
        print("\n--- Deposit Funds ---")
        wallet_no = int(input("Target Wallet (1 or 2): "))
        amount = int(input("Amount to deposit: $"))

        if wallet_no == 1:
            w1.add_money(amount)
        elif wallet_no == 2:
            w2.add_money(amount)
        else:
            print("[!] Error: Unrecognized wallet ID.")

    elif choice == 2:
        # Route expenditure to the targeted wallet
        print("\n--- Spend Funds ---")
        wallet_no = int(input("Target Wallet (1 or 2): "))
        amount = int(input("Amount to spend: $"))

        if wallet_no == 1:
            w1.spend_money(amount)
        elif wallet_no == 2:
            w2.spend_money(amount)
        else:
            print("[!] Error: Unrecognized wallet ID.")

    elif choice == 3:
        # Execute cross-wallet transaction
        print("\n--- Transfer Funds ---")
        sender = int(input("Transfer FROM Wallet (1 or 2): "))
        receiver = int(input("Transfer TO Wallet (1 or 2): "))
        amount = int(input("Amount to transfer: $"))

        if sender == 1 and receiver == 2:
            w1.transfer(w2, amount)
        elif sender == 2 and receiver == 1:
            w2.transfer(w1, amount)
        else:
            print("[!] Error: Invalid sender/receiver combination.")

    elif choice == 4:
        # Output financial summary for both accounts
        print("\n--- Account Balances ---")
        print("Wallet [1]:")
        w1.show_balance()
        print("Wallet [2]:")
        w2.show_balance()
        print("-" * 24)

    elif choice == 5:
        # Terminate the application loop safely
        print("\n[*] Exiting Application. Goodbye!")
        break

    else:
        # Handle unrecognized menu inputs
        print("[!] Error: Invalid choice. Please select an option from 1 to 5.")