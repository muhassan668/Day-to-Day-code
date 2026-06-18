# pop/del removes using keys
# clear removes everything 
# 'in' checks keys in dictionaries not the value 

# students = [
#     {"name": "Ali", "marks": 78},
#     {"name": "Ahmed", "marks": 45},
#     {"name": "Hassan", "marks": 92}
# ]
# for student in students:
#     print(student["name"], student["marks"])


# student = {
#     "name": "Hassan",
#     "marks": 92,
#     "gpa": 3.7
# }
# for key,value in student.items():
#     print(key,":",value)
# student["department"] = "CS"
# for key,value in student.items():
#     print(key,":",value)
# student["marks"] = 95
# if "gpa" in student:
#     print("GPA is available")
# else:
#     print("GPA is not available")
# for key,value in student.items():
#     print(key,value)


# students = [
#     {"name": "Ali", "marks": 78},
#     {"name": "Ahmed", "marks": 45},
#     {"name": "Hassan", "marks": 92},
#     {"name": "Bilal", "marks": 67},
#     {"name": "Usman", "marks": 33}
# ]
# for student in students:
#     print(student["name"],":",student["marks"])
# passing = []
# failing = []
# for student in students:
#     if student["marks"] >= 50:
#         passing.append(student)
#     else:
#         failing.append(student)
# print("Passing students:")
# for student in passing:
#     print(student)
# print("Failing students:")
# for student in failing:
#     print(student)
# marks = []
# for student in students:
#     marks.append(student["marks"])
# print("Highest Marks:",max(marks))
# average = sum(marks)/len(marks)
# print("Average Marks:",average)

# sorted_students = sorted(students, key=lambda student: student["marks"], reverse=True)
# print(sorted_students)
# for student in sorted_students:
#     print(student["name"], ":", student["marks"])

# students = {
#     "u001": {
#         "name": "Ali",
#         "marks": 78,
#         "gpa": 3.1
#     },
#     "u002": {
#         "name": "Ahmed",
#         "marks": 45,
#         "gpa": 2.4
#     },
#     "u003": {
#         "name": "Hassan",
#         "marks": 92,
#         "gpa": 3.7
#     }
# }
# for student_id, info in students.items():
#     print(student_id, info["name"], info["marks"], info["gpa"])

# passing_students = {}
# for student_id, info in students.items():
#     if info["marks"] >= 50:
#         passing_students[student_id] = info
# print(passing_students)

# sorted_students = sorted(
#     students.items(),
#     key=lambda item: item[1]["marks"],
#     reverse=True
# )
# print(sorted_students)


# students = {
#     "u001": {"name": "Ali", "marks": 78, "gpa": 3.1},
#     "u002": {"name": "Ahmed", "marks": 45, "gpa": 2.4},
#     "u003": {"name": "Hassan", "marks": 92, "gpa": 3.7},
#     "u004": {"name": "Bilal", "marks": 67, "gpa": 3.0},
#     "u005": {"name": "Usman", "marks": 33, "gpa": 2.0}
# }
# for id, info in students.items():
#     print(id,info["name"],info["marks"],info["gpa"])
# passing = {}
# failing = {}
# for id,info in students.items():
#     if info["marks"]>=50:
#         passing[id] = info
#     else:
#         failing[id] = info
# print("Passing students:",passing)
# print("Failing students:", failing)
# marks = [info["marks"] for id,info in students.items()]
# print("Highest:",max(marks))
# print("Average:",sum(marks)/len(marks))
# sorted_students = sorted(
#     students.items(),
#     key=lambda item:item[1]["marks"],
#     reverse=True
# )
# for id,info in sorted_students:
#     print(id,info["name"],info["marks"],info["gpa"])
# print(type(sorted_students))
# print(type(students))
# print(type(passing))
# print(type(marks))


# university = {
#     "name": "GIKI",
#     "department": "Computer Science",
#     "students": [
#         {
#             "id": "u001",
#             "name": "Ali",
#             "marks": 78,
#             "courses": ["DSA", "DLD"]
#         },
#         {
#             "id": "u002",
#             "name": "Ahmed",
#             "marks": 45,
#             "courses": ["Discrete", "Linear Algebra"]
#         },
#         {
#             "id": "u003",
#             "name": "Hassan",
#             "marks": 92,
#             "courses": ["DSA", "Discrete", "DLD"]
#         }
#     ]
# }
# print(university["students"][2]["courses"][0])
# for student in university["students"]:
#     print(student["name"], "courses:")
#     for course in student["courses"]:
#         print("-", course)

    

university = {
    "name": "GIKI",
    "department": "Computer Science",
    "students": [
        {
            "id": "u001",
            "name": "Ali",
            "marks": 78,
            "courses": ["DSA", "DLD"]
        },
        {
            "id": "u002",
            "name": "Ahmed",
            "marks": 45,
            "courses": ["Discrete", "Linear Algebra"]
        },
        {
            "id": "u003",
            "name": "Hassan",
            "marks": 92,
            "courses": ["DSA", "Discrete", "DLD"]
        }
    ]
}
print(university["name"])
print(university["department"])
passing = []
print("Names:")
for student in university["students"]:
    if student["marks"]>=50:
        passing.append(student)
    print(student["name"])
print("Passing students:",passing)
marks = [student["marks"] for student in university["students"]]
print("Highest marks:",max(marks))
print("Average marks:",sum(marks)/len(marks))
print()
for student in university["students"]:
    print(student["name"],":",student["courses"])
sorted_students = sorted(
    university["students"],
    key=lambda student: student["marks"],
    reverse=True
)
for student in sorted_students:
    print(student["id"], student["name"], student["marks"])