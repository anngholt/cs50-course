import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database_file = sys.argv[1]
    sequence_file = sys.argv[2]
    try:
        with open(database_file, newline='') as csvfile:
            reader = csv.DictReader(csvfile)
            #print(f"Fieldnames: {reader.fieldnames}")  # Debugging line
            database_data = list(reader)
            str_names = reader.fieldnames[1:]
    except FileNotFoundError:
        print(f"Error: File '{database_file}' not found.")


    #Read DNA sequence file into a variable
    try:
        with open(sequence_file) as f:
            sequence = f.read()
    except FileNotFoundError:
        print(f"Error: File '{sequence_file}' not found.")
        exit(1)

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_seq in str_names:
        str_counts[str_seq] = longest_match(sequence, str_seq)
    
    print("STR counts:", str_counts)
    
    # Check database for matching profiles
    for person in database_data:
       if all(int(person[str_seq]) == str_counts[str_seq] for str_seq in str_names):
            print("Match:", person['name'])
            return

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
