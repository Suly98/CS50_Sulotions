from cs50 import get_int

# Prompt the user for a height between 1 and 8
h = get_int("Height: ")

# Ensure the height is valid (between 1 and 8)
while (h < 1 or h > 8):
    h = get_int("Height: ")

# Loop through each row
for i in range(1, h + 1):
    # Calculate the number of spaces needed for the current row
    space = (h - i) * " "
    # Calculate the number of hashes needed for the current row
    hashes = i * '#'

    # Print the spaces followed by the hashes on the same line
    print(space, end='')
    print(hashes)
