def main():
    card_number = input("Number: ").strip()

    if not card_number.isdigit():
        print("INVALID")
        return
    if luhn_algorithm(card_number):
        print(get_card_type(card_number))
    else:
        print("INVALID")

def luhn_algorithm(card_number):
    total = 0
    reverse_digits = card_number[::-1]

    for i, digit in enumerate(reverse_digits):
        n = int(digit)
        if i % 2 == 1:  # every second digit from the end
            n *= 2
            if n > 9:
                n -= 9
        total += n
        
    return total % 10 == 0

def get_card_type(card_number):
    length = len(card_number)
    first_digit = int(card_number[0])
    first_two = int(card_number[:2])

    if length == 15 and first_two in [34, 37]:
        return "AMEX"
    elif length == 16 and 51 <= first_two <= 55:
        return "MASTERCARD"
    elif first_digit == 4 and length in [13, 16]:
        return "VISA"
    else:
        return "INVALID"

main()