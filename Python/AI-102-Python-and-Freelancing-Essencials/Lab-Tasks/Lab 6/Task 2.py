class Course:
    def __init__(self, course_name, max_students):
        # Initialize course attributes and encapsulate the student list
        self.course_name = course_name
        self.max_students = max_students
        self.__students = []

    def enroll(self, student_name):
        # Registers a student if the course hasn't reached maximum capacity
        if len(self.__students) < self.max_students:
            self.__students.append(student_name)
            print(f"[+] Success: {student_name} has been enrolled in {self.course_name}.")
            return True
        else:
            print(f"[!] Alert: Registration failed. {self.course_name} is currently full.")
            return False

    def remove(self, student_name):
        # Unregisters a student if they are currently enrolled in the course
        if student_name in self.__students:
            self.__students.remove(student_name)
            print(f"[-] Success: {student_name} has been removed from {self.course_name}.")
        else:
            print(f"[!] Error: {student_name} is not enrolled in {self.course_name}.")

    def available_seats(self):
        # Calculates and returns the number of open seats
        return self.max_students - len(self.__students)

    def show_students(self):
        # Displays the current status and roster for the course
        print(f"  Course: {self.course_name}")
        print(f"  Enrolled Students: {self.__students if self.__students else 'None'}")
        print(f"  Available Seats: {self.available_seats()} out of {self.max_students}")


# Initialize the course objects
c1 = Course("Python", 3)
c2 = Course("C++", 2)

# Track the first course to reach full capacity
first_full = None

# Main Application Loop
while True:
    print("MAIN MENU:")
    print("  [1] Enroll a Student")
    print("  [2] Remove a Student")
    print("  [3] View Course Details")
    print("  [4] View First Full Course")
    print("  [5] Exit Application")
    print()

    choice = int(input("Select an option (1-5): "))

    if choice == 1:
        # Handle enrollment for the selected course
        print("\n--- Enroll Student ---")
        course_no = int(input("Select Course (1 for Python, 2 for C++): "))
        student_name = input("Enter student's name: ")

        if course_no == 1:
            c1.enroll(student_name)
            # Update tracker if Python fills up first
            if c1.available_seats() == 0 and first_full is None:
                first_full = c1.course_name
        elif course_no == 2:
            c2.enroll(student_name)
            # Update tracker if C++ fills up first
            if c2.available_seats() == 0 and first_full is None:
                first_full = c2.course_name
        else:
            print("[!] Error: Invalid course selection.")

    elif choice == 2:
        # Handle removal of a student from the selected course
        print("\n--- Remove Student ---")
        course_no = int(input("Select Course (1 for Python, 2 for C++): "))
        student_name = input("Enter student's name to remove: ")

        if course_no == 1:
            c1.remove(student_name)
        elif course_no == 2:
            c2.remove(student_name)
        else:
            print("[!] Error: Invalid course selection.")

    elif choice == 3:
        # Output the current roster and details for all courses
        print("\n--- Course Details ---")
        c1.show_students()
        print("")
        c2.show_students()
        print("-" * 22)

    elif choice == 4:
        # Display the tracker status
        print("\n--- Capacity Tracker ---")
        if first_full is not None:
            print(f"[*] The first course to reach maximum capacity was: {first_full}")
        else:
            print("[*] Status: No courses are completely full yet.")

    elif choice == 5:
        # Terminate the application cleanly
        print("\n[*] Exiting Course Enrollment System. Goodbye!")
        break

    else:
        # Handle invalid menu selections
        print("[!] Error: Invalid choice. Please select an option from 1 to 5.")