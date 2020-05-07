from cs50 import get_string


# main function
def main():
    # Get the text from user
    text = get_string("Text: ")

    # Get the stats of the input text
    L = countletters(text)
    W = countwords(text)
    S = countsentences(text)

    L = (L * 100.0) / W
    S = (S * 100.0) / W

    # Calculate the Coleman-Liau Value according to input text
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


# Function to count the number of letters in the text
def countletters(text):
    count = 0
    for i in text:
        if i.isalpha():
            count += 1
    return count


# Function to count the number of words in the text
def countwords(text):
    return len(text.split())


# Function to count the number of sentences in the text
def countsentences(text):
    count = 0
    for i in text:
        if i == '.' or i == '!' or i == '?':
            count += 1
    return count


main()