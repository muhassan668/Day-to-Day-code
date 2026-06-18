class LibraryMember:
    def __init__(self, member_name):
        # Initialize member identity and encapsulate their borrowed books registry
        self.member_name = member_name
        self.__borrowed_books = {}
        self.total_fine = 0

    def borrow_book(self, title):
        # Registers a book to the member's account if it hasn't been checked out already
        if title in self.__borrowed_books:
            print(f"[!] Alert: '{title}' is already currently borrowed by {self.member_name}.")
        else:
            self.__borrowed_books[title] = 0
            print(f"[+] Success: '{title}' has been issued to {self.member_name}.")

    def return_book(self, title, days_late):
        # Processes book returns, calculates applicable late fees, and updates total fines
        if title not in self.__borrowed_books:
            print(f"[!] Error: '{title}' was not found in {self.member_name}'s borrowed list.")
            return

        fine = 0
        if 0 <= days_late <= 3:
            fine = 0
        elif 4 <= days_late <= 7:
            fine = 5
        elif days_late > 7:
            fine = 10
        else:
            print("[!] Error: Invalid number of late days entered.")
            return

        del self.__borrowed_books[title]
        self.total_fine += fine

        print(f"[-] Success: '{title}' has been returned successfully.")
        if fine > 0:
            print(f"[*] A late fine of Rs. {fine} has been applied.")
        else:
            print("[*] Returned on time. No fines applied.")

    def show_details(self):
        # Displays the member's active checkouts and total accrued fines
        print(f"  Member Name: {self.member_name}")
        # Format the dictionary keys into a clean list for display
        books_list = list(self.__borrowed_books.keys())
        print(f"  Borrowed Books: {books_list if books_list else 'None'}")
        print(f"  Outstanding Fines: Rs. {self.total_fine}")


# Instantiate library members
m1 = LibraryMember("Salman")
m2 = LibraryMember("Ahmed")
m3 = LibraryMember("Ali")

# Main Application Loop
while True:
    print("MAIN MENU:")
    print("  [1] Borrow a Book")
    print("  [2] Return a Book")
    print("  [3] View Member Details")
    print("  [4] View All Outstanding Fines")
    print("  [5] Exit System")
    print()

    # Robust input handling for menu selection
    try:
        choice = int(input("Select an option (1-5): "))
    except ValueError:
        print("[!] Error: Please enter a valid numerical choice.")
        continue

    if choice == 1:
        # Handle the book borrowing process
        print("\n--- Borrow Book ---")
        try:
            member_no = int(input("Select Member (1: Salman, 2: Ahmed, 3: Ali): "))
            title = input("Enter book title: ")

            if member_no == 1:
                m1.borrow_book(title)
            elif member_no == 2:
                m2.borrow_book(title)
            elif member_no == 3:
                m3.borrow_book(title)
            else:
                print("[!] Error: Unrecognized member ID.")
        except ValueError:
            print("[!] Error: Member ID must be a number.")

    elif choice == 2:
        # Handle the book return and fine calculation process
        print("\n--- Return Book ---")
        try:
            member_no = int(input("Select Member (1: Ali, 2: Ahmed, 3: Sara): "))
            title = input("Enter book title: ")
            days_late = int(input("Enter number of days late: "))

            if member_no == 1:
                m1.return_book(title, days_late)
            elif member_no == 2:
                m2.return_book(title, days_late)
            elif member_no == 3:
                m3.return_book(title, days_late)
            else:
                print("[!] Error: Unrecognized member ID.")
        except ValueError:
            print("[!] Error: Numeric input required for Member ID and days late.")

    elif choice == 3:
        # Output current details for all registered members
        print("\n--- Member Profiles ---")
        print("[ Member 1 ]")
        m1.show_details()
        print("\n[ Member 2 ]")
        m2.show_details()
        print("\n[ Member 3 ]")
        m3.show_details()
        print("-" * 23)

    elif choice == 4:
        # Provide a summary of all fines across the library system
        print("\n--- Total Outstanding Fines ---")
        print(f"  {m1.member_name}: Rs. {m1.total_fine}")
        print(f"  {m2.member_name}: Rs. {m2.total_fine}")
        print(f"  {m3.member_name}: Rs. {m3.total_fine}")
        print("-" * 29)

    elif choice == 5:
        # Terminate the application safely
        print("\n[*] Shutting down Library Management System. Goodbye!")
        break

    else:
        # Catch numeric inputs outside the expected 1-5 range
        print("[!] Error: Invalid choice. Please select an option from 1 to 5.")