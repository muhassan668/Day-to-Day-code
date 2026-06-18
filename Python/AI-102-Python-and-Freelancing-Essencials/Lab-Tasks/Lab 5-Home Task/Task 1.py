#Name: Muhammad Hassan   |Reg#: 2025537

def count_character_frequency(text):
    frequency_dict = {}
    
    for char in text:
        if char in frequency_dict:
            frequency_dict[char] += 1
        else:
            frequency_dict[char] = 1
            
    return frequency_dict

# Get input from the user
user_string = input("Enter a string: ")

# Calculate and print the frequency
result = count_character_frequency(user_string)
print("Character frequencies:", result)