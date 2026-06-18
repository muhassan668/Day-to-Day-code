# thislist = ["apple", 5, "banana", 7]
# print(thislist)
# print(len(thislist))
# print(type(thislist))

# for i in range(len(thislist)):
#     print(i, thislist[i])

# append add at end 
# insert add at index 
# remove by value 
# pop removes by index 
# del    "     "   "
# clear  "    everything

# if "apple" in/not in thislist:
#     print("found")
# else:
#     print("not found")

# count number of that things
# index tells where it is 

# names = ["Ali", "Ahmed", "Hassan"]

# search = "Bilal"

# if search in names:
#     print(names.index(search))
# else:
#     print("Not found")

# reverse by [::-1] also by reverse 
# sort sorts in ascending order 
# list.sort(reverse=True) sorts in descending order 
# sorted returns new sorted list 
# copy list by using .copy and assigning it to new one 
# nested list works as 2d array 

# matrix = [
#     [1, 2, 3],
#     [4, 5, 6],
#     [7, 8, 9]
# ]
# for row in matrix:
#     for value in row:
#         print(value, end=" ")
#     print()

# newlist = [dash for dash in oldlist if condition\range]
 
# sum,max,min,len 


# marks = [1,2,3,4,5]
# print(max(marks))
# print(min(marks))
# average = sum(marks)/len(marks)
# print(average)
# names = ["Ali", "Ahmed", "Hassan", "Bilal"]
# name = input("Enter a name: ")
# if name in names:
#     print("Name is found.")
# else: 
#     print("Name is not found.")
# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# even = [num for num in numbers if num%2 == 0]
# odd = [num for num in numbers if num%2 != 0]
# print(even)
# print(odd)
# marks = [45, 80, 32, 90, 67, 50]
# passing = []
# for mark in marks:
#     if mark>=50:
#         passing.append(mark)
# print(passing)
# students = [
#     ["Ali", 3.1],
#     ["Ahmed", 2.8],
#     ["Hassan", 3.7]
# ]
# passing = []
# for name, gpa in students:
#     if gpa >3.0:
#         passing.append([name,gpa])
# print(passing)
# passing = [[name,gpa] for name,gpa in students if gpa>3]

# extend adds multiple items in the list 
# enumirate used for both index and value 
# zip used to combine two lists(related) 

# names = ["Ali", "Ahmed", "Hassan"]
# marks = [80, 75, 90]
# for name, mark in zip(names, marks):
#     print(name, mark)


# for nested lists use deepcopy 
# import copy
# a = [[1, 2], [3, 4]]
# b = copy.deepcopy(a)
# b[0][0] = 99
# print(a)
# print(b)


students = [
    ["Ali", 78],
    ["Ahmed", 45],
    ["Hassan", 92],
    ["Bilal", 67],
    ["Usman", 33]
]
print("All students:")
for name, marks in students:
    print(name, marks)
print()
print("Passing students:")
passing = [[name, marks] for name, marks in students if marks >= 50]
print(passing)
print()
print("Failing students:")
failing = [[name, marks] for name, marks in students if marks < 50]
print(failing)
print()
marks_list = []
for name, marks in students:
    marks_list.append(marks)
highest = max(marks_list)
average = sum(marks_list) / len(marks_list)
print("Highest marks:", highest)
print("Average marks:", average)
print()
names = []
for name, marks in students:
    names.append(name)
print("Names:")
print(names)
print()
sorted_students = sorted(students, key=lambda student: student[1], reverse=True)
print("Sorted by marks:")
print(sorted_students)

