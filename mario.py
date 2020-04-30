from cs50 import get_int

def main():
    size = get_input()

    for i in range(1, size + 1):
        print(" "*(size - i) + "#"*i + "  " + "#"*i)


def get_input():
    while True:
        n = get_int("Height: ")
        if n in range(1,9):
            break
    return n

main()