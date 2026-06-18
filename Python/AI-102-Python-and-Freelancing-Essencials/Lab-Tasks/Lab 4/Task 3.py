def factorial():
    while True:
        x = int(input("Enter a possitive number to find it's factorial:"))
        if (x<0):                       #exception handling so that negative number cannot be input
            print("Invalid Input!")
        else:
            break
    if x==0 or x==1:
        return 1
    else :
        fact = 1
        for i in range(x,0,-1):         #finding the factorial using loops
            fact = fact*i
    return fact
 
print("The factorial is",factorial())