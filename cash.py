def main():
    while True:
        try:
            change = float(input("Change: "))
            if change >= 0:
                break
        except ValueError:
            pass  # ignore invalid input and ask again

    cents = round(change * 100)  

    coins = 0
    for coin in [25, 10, 5, 1]:
        coins += cents // coin # integer division
        cents %= coin # gives the remainder after division

    print(coins)

main()
