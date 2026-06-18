name = "Muhammad Hassan"
age = 18
uni = "GIK Institute"
gpa = 2.8

print("My name is", name, ". I am", age, "years old. I study at", uni, ".", "My GPA is", gpa, ".")
print("My name is %s. I am %d years old. I study at %s. My GPA is %f." % (name, age, uni, gpa))
print("My name is " + name + ". I am " + str(age) + " years old. I study at " + uni + "." + " My GPA is " + str(gpa) + ".")
print(f"My name is {name}. I am {age} years old. I study at {uni}. My GPA is {gpa}.")
print("My name is {}. I am {} years old. I study at {}. My GPA is {}.".format(name, age, uni, gpa))
print("My name is {0}. I am {1} years old. I study at {2}. My GPA is {3}.".format(name, age, uni, gpa))