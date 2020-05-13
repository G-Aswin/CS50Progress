from sys import argv, exit
import csv


# Checks if the arguements are alright and if so, copies them to their respective variables.
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

csv_root = argv[1]
dna_root = argv[2]


# Opens the CSV file and ONLY reads the first line so as to know which str's to search for.
with open(csv_root, newline="") as csvfile:
    row = csv.reader(csvfile)
    for header in row:
        head = header
        break
    head.pop(0)


# Opens the CSV file and uses DictReader to store all the data as a list of dictionary.
# Each dictionary contains str as key and the longest continuous strand as the value.
with open(csv_root, newline="") as csvfile:
    reader = csv.DictReader(csvfile)
    dna_data = []
    for dict in reader:
        dna_data.append(dict)


# Opens the dna data to be searched for and stores the dna sequence in a string called dna.
file = open(dna_root, "r")

for line in file:
    dna = line


# An empty dictionary to store the information extracted
ext_data = {}


# For every str, this block finds out the longest streak of that str and stores it in the dictionary of dna data.
for seq in head:
    originalseq = seq
    streak = 0
    while True:
        if seq in dna:
            streak += 1
            seq += originalseq
        else:
            break
    ext_data[originalseq] = str(streak)


# This block searches for a dictionary in the whole database which matches all str streak values.
# If found, name of the person is printed, else, No match.
flag = 0
for dic in dna_data:
    matchedseq = 0
    for seq in head:
        if dic[seq] == ext_data[seq]:
            matchedseq += 1
    if matchedseq == len(head):
        print(dic['name'])
        flag = 1
if flag == 0:
    print("No match")