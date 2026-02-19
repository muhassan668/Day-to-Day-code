print("Welcome to Die Rolling Simulator!")
import random
def roll_die():
    return random.randint(1, 6)
while True:
    input("Press Enter to roll the die...")
    result = roll_die()
    print(f"You rolled a {result}!")
    play_again = input("Do you want to roll again? (yes/no): ")
    if play_again.lower() != "yes" and play_again.lower() != "y":
        print("Thanks for playing! Goodbye!")
        break
