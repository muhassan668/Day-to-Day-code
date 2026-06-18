#Name: Muhammad Hassan   |Reg#: 2025537

def get_word_frequency(sentence):
    word_dict = {}
    
    # Convert the sentence to lowercase to ignore capitalization
    sentence = sentence.lower()
    
    # Split the sentence into a list of words based on spaces
    words = sentence.split()
    
    for word in words:
        if word in word_dict:
            word_dict[word] += 1
        else:
            word_dict[word] = 1
            
    return word_dict

# Get input from the user
user_input = input("Enter a sentence: ")

# Call the function and print the result
result = get_word_frequency(user_input)
print("Word frequencies:", result)