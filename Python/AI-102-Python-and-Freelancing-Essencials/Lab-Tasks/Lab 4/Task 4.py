def max(a,b,c):             # function to check which of the three numbers is the largest by compairing them with each other
    if a>b and a>c:
            m = a
    elif b>a and b>c:
            m = b
    else:
        m = c       
    return m
x = int(input("Enter the first number:"))
y = int(input("Enter the second number:"))
z = int(input("Enter the third number:"))
 
print("The maximum number from the three is",max(x,y,z))