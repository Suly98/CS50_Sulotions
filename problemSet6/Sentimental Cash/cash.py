from cs50 import get_float


change = get_float("Change: ")

while change <= 0:
    change = get_float("Change: ")

cents = round(change * 100)
count = 0

while cents >= 25:
    cents -= 25
    count += 1

while cents >= 10:
    cents -= 10
    count += 1

while cents >= 5:
    cents -= 5
    count += 1

while cents >= 1:
    cents -= 1
    count += 1

print(count)
