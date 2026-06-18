class Product:
    def __init__(self, name, price):
        # Initialize product attributes and encapsulate the stock level
        self.name = name
        self.price = price
        self.__stock = 0

    def add_stock(self, quantity):
        # Validates and increments the stock level for the product
        if quantity <= 0:
            print("[!] Error: Invalid quantity. Must be greater than 0.")
        else:
            self.__stock += quantity
            print(f"[+] Success: {quantity} units added to {self.name} inventory.")

    def sell(self, quantity):
        # Processes a sale and deducts from inventory if sufficient stock exists
        if quantity <= 0:
            print("[!] Error: Invalid quantity. Must be greater than 0.")
        elif quantity > self.__stock:
            print(f"[!] Error: Insufficient stock. Only {self.__stock} units available.")
        else:
            self.__stock -= quantity
            print(f"[-] Success: {quantity} units of {self.name} sold.")

    def stock_value(self):
        # Calculates the total monetary value of the current stock
        return self.price * self.__stock

    def show_details(self):
        # Displays formatted product information
        print(f"  Product Name: {self.name}")
        print(f"  Unit Price:   Rs. {self.price:,}")
        print(f"  Stock Value:  Rs. {self.stock_value():,}")


# Instantiate inventory items
p1 = Product("Laptop", 50000)
p2 = Product("Phone", 30000)
p3 = Product("Tablet", 20000)

# Main Application Loop
while True:
    print("MAIN MENU:")
    print("  [1] Add Stock")
    print("  [2] Sell Product")
    print("  [3] View Product Details")
    print("  [4] View Highest Value Product")
    print("  [5] Exit Application")
    print()

    # try-except block to handle accidental text/letter inputs
    try:
        choice = int(input("Select an option (1-5): "))
    except ValueError:
        print("[!] Error: Please enter a valid number.")
        continue

    if choice == 1:
        # Handle stock replenishment
        print("\n--- Replenish Stock ---")
        try:
            product_no = int(input("Select Product (1: Laptop, 2: Phone, 3: Tablet): "))
            quantity = int(input("Enter quantity to add: "))

            if product_no == 1:
                p1.add_stock(quantity)
            elif product_no == 2:
                p2.add_stock(quantity)
            elif product_no == 3:
                p3.add_stock(quantity)
            else:
                print("[!] Error: Unrecognized product ID.")
        except ValueError:
            print("[!] Error: Input must be a valid number.")

    elif choice == 2:
        # Handle sales transactions
        print("\n--- Process Sale ---")
        try:
            product_no = int(input("Select Product (1: Laptop, 2: Phone, 3: Tablet): "))
            quantity = int(input("Enter quantity to sell: "))

            if product_no == 1:
                p1.sell(quantity)
            elif product_no == 2:
                p2.sell(quantity)
            elif product_no == 3:
                p3.sell(quantity)
            else:
                print("[!] Error: Unrecognized product ID.")
        except ValueError:
            print("[!] Error: Input must be a valid number.")

    elif choice == 3:
        # Output current inventory status for all products
        print("\n--- Inventory Status ---")
        print("[ Product 1 ]")
        p1.show_details()
        print("\n[ Product 2 ]")
        p2.show_details()
        print("\n[ Product 3 ]")
        p3.show_details()
        print("-" * 24)

    elif choice == 4:
        # Determine and display the product with the maximum stock value
        print("\n--- Highest Value Asset ---")
        max_product = p1

        if p2.stock_value() > max_product.stock_value():
            max_product = p2
        if p3.stock_value() > max_product.stock_value():
            max_product = p3

        print(f"[*] The product with the highest total stock value is: {max_product.name}")
        print(f"[*] Total Value: Rs. {max_product.stock_value():,}")

    elif choice == 5:
        # Terminate the loop and exit safely
        print("\n[*] Exiting Inventory Management System. Goodbye!")
        break

    else:
        # Catch numeric inputs outside the 1-5 range
        print("[!] Error: Invalid choice. Please select an option from 1 to 5.")