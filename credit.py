from cs50 import get_int
from sys import exit

# Main Function


def main():

    # Get the credit card number from the user
    number = get_int("Number: ")
    number = str(number)

    # Check for Validity of the Credit Card Number
    validity = checksum(number)
    if validity == False:
        print("INVALID")
        exit(0)

    # Check for AMEX
    if len(number) == 15:

        if number[0] == '3':

            if number[1] == '4' or number[1] == '7':
                print("AMEX")

            else:
                print("INVALID")

        else:
            print("INVALID")

    # Check for MASTERCARD or VISA
    elif len(number) == 16:

        if number[0] == '5':

            if number[1] in ('1', '2', '3', '4', '5'):
                print("MASTERCARD")

            else:
                print("INVALID")

        elif number[0] == '4':
            print("VISA")

        else:
            print("INVALID")

    # Check for VISA
    elif len(number) == 13:

        if number[0] == '4':
            print("VISA")

        else:
            print("INVALID")

    else:
        print("INVALID")


# Function to check validity of a credit number
def checksum(number):
    # Declaration of variables
    num = int(number)
    evesum = 0
    oddsum = 0

    # Getting one number at a time
    while num != 0:
        evesum += num % 10
        num //= 10

        temp = (num % 10) * 2
        while temp != 0:
            oddsum += temp % 10
            temp //= 10
        num //= 10

    # Check for validity
    if (oddsum + evesum) % 2 == 0:
        return True
    else:
        return False


main()