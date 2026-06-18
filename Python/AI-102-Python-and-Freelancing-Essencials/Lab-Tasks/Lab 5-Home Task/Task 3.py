#Name: Muhammad Hassan   |Reg#: 2025537

def extract_email_components(email_list):
    email_dict = {}
    
    for email in email_list:
        username, domain = email.split('@')
        email_dict[username] = domain
        
    return email_dict

# Get a single string from the user
user_email = input("Enter Email: ")

# Put the single string inside a list so the function can process it properly
result = extract_email_components([user_email])

print("Email dictionary:", result)