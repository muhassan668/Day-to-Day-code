#Name: Muhammad Hassan   |Reg#: 2025537

def get_vowel_counts(text):
    vowels = "aeiou"
    vowel_dict = {}
    
    # Convert text to lowercase to ignore capitalization
    text = text.lower()
    
    for char in text:
        # Only process the character if it is a vowel
        if char in vowels:
            if char in vowel_dict:
                vowel_dict[char] += 1
            else:
                vowel_dict[char] = 1
                
    return vowel_dict

# Get a string from the user
user_input = input("Enter a string: ")

# Call the function and print the result
result = get_vowel_counts(user_input)
print("Vowel counts:", result)