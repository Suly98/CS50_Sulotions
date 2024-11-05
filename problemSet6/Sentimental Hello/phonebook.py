people = [
    {"name": "David", "Number": "+1 319944 445"},
    {"name": "Carter", "Number": "+2 322- 23323"}
]

name = input("Enter name: ")

for person in people:
    if person["name"] == name:
        number = person["Number"]
        print(f"Found {number}")
        break

else:
    print("Not found!")
