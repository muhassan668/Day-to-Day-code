print()
print("Finding Even or Odd")
 
def func(n):            #defining the function to find even or odd
    if n%2==0:          #if the remainder with 2 is 0 then it is even
        print("The number is even.")
    else :              #if the remainder with 2 is not 0 then it is odd
        print("The number is odd.")
    
while True:             #exception handling
    num = int(input("Enter a number(-100 to exit): "))
    if num == -100:     #condition for exiting the program
        print("Program Exited")
        break
    elif num == 0 :
        print("0 is neither odd nor even")
    else :
        func(num)       #calling the function