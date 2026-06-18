class Candidate:
    def __init__(self, name):
        # Initialize candidate identity and encapsulate the vote tally
        self.name = name
        self.__votes = 0

    def add_vote(self):
        # Increments the private vote counter by one
        self.__votes += 1

    def get_votes(self):
        # Returns the current total of accumulated votes
        return self.__votes

    def show_details(self):
        # Displays formatted candidate information and current standing
        print(f"  Candidate: {self.name}")
        print(f"  Total Votes: {self.get_votes()}")


# Instantiate election candidates
c1 = Candidate("Salman")
c2 = Candidate("Ahmed")
c3 = Candidate("Ali")

# System Header
print("=" * 45)
print("      Hassan's Election Voting System      ")
print("=" * 45)

# Main Application Loop
while True:
    print("\n" + "-" * 30)
    print("           MAIN MENU           ")
    print("-" * 30)
    print("  [1] Cast a Vote")
    print("  [2] View Candidate Standings")
    print("  [3] Announce Current Winner")
    print("  [4] Exit Polling Station")
    print("-" * 30)

    # Robust input handling for menu selection
    try:
        choice = int(input(">> Select an option (1-4): "))
    except ValueError:
        print("[!] Error: Please enter a valid numerical choice.")
        continue

    if choice == 1:
        # Handle the voting process
        print("\n--- Cast Your Vote ---")
        try:
            candidate_no = int(input("Select Candidate (1: Salman, 2: Ahmed, 3: Ali): "))

            if candidate_no == 1:
                c1.add_vote()
                print(f"[+] Success: Vote officially recorded for {c1.name}.")
            elif candidate_no == 2:
                c2.add_vote()
                print(f"[+] Success: Vote officially recorded for {c2.name}.")
            elif candidate_no == 3:
                c3.add_vote()
                print(f"[+] Success: Vote officially recorded for {c3.name}.")
            else:
                print("[!] Error: Unrecognized candidate ID. Vote discarded.")
        except ValueError:
            print("[!] Error: Input must be a valid number.")

    elif choice == 2:
        # Output current voting metrics for all candidates
        print("\n--- Current Standings ---")
        c1.show_details()
        print("")
        c2.show_details()
        print("")
        c3.show_details()
        print("-" * 25)

    elif choice == 3:
        # Determine and display the candidate with the most votes, handling ties
        print("\n--- Election Results ---")
        
        # Group candidates into a list for easier evaluation
        candidates = [c1, c2, c3]
        
        # Find the maximum number of votes currently held by anyone
        max_votes = max(c.get_votes() for c in candidates)
        
        # Check if any votes have been cast at all
        if max_votes == 0:
            print("[*] No votes have been cast yet.")
        else:
            # Build a list of all candidates who have that maximum vote count
            leaders = [c for c in candidates if c.get_votes() == max_votes]

            # Check if more than one candidate shares the highest score
            if len(leaders) > 1:
                # Join their names together with commas
                tied_names = ", ".join(c.name for c in leaders)
                print(f"[*] It is currently a tie between: {tied_names}")
                print(f"[*] Votes Secured: {max_votes} each")
            else:
                print(f"[*] The current frontrunner/winner is: {leaders[0].name}")
                print(f"[*] Total Votes Secured: {max_votes}")

    elif choice == 4:
        # Terminate the polling session safely
        print("\n[*] Closing Polling Station. Goodbye!")
        break

    else:
        # Catch numeric inputs outside the expected 1-4 range
        print("[!] Error: Invalid choice. Please select an option from 1 to 4.")