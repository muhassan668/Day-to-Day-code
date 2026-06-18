print("Calculating Power")
 
def calculate_power(a,b):       #defining the power finding function
    z = a
    for i in range(b,1,-1):     #using loops to find the answer
        z = z*a
    return z
x = int(input("Enter the base:"))
while True:
    y = int(input("Enter the power:"))
    if y<0:
        print("Power cannot be negative!")
    else:
        break
print()
 
print(x,"to the power",y,"=",calculate_power(x,y))