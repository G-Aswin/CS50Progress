# Importing get_int from the cs50 library
from cs50 import get_int


# Main Function
def main():
    # Gets correct size from the user
    size = get_input()

    # For printing out the pattern
    for i in range(1, size + 1):
        print((" " * (size - i)) + ("#" * i) + ("  ") + ("#" * i))


# Function to get the correct range of inputs
def get_input():
    while True:
        n = get_int("Height: ")
        if n in range(1, 9):
            break
    return n


# Runs the Main Function
main()