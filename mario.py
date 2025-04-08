def main():
    height = int(input("Enter pyramid height: "))
    print_row(1, height)

def print_chars(char, count):
    if count <= 0:
        return
    print(char, end="")
    print_chars(char, count - 1)

def print_row(row, total_rows):
    if row > total_rows:
        return

    spaces = total_rows - row

    # Print leading spaces
    print_chars(" ", spaces)

    # Print left hashes
    print_chars("#", row)

    # Print middle gap
    print_chars(" ", 2)

    # Print right hashes
    print_chars("#", row)

    print()

    # Recursive call for next row
    print_row(row + 1, total_rows)

main()
