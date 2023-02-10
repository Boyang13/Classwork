# TODO
from cs50 import get_float

# gets change owed from user
dollars = 0
while (dollars <= 0):
    dollars = get_float("Change owed(in dollars): ")

# gets number of coins and nearest integer of coins
coins = 0
cents = round(dollars * 100, 0)

# count coins until the change owed is 0
# first quarters, then dimes, then nickels, then cents
# elif = else if
while (cents > 0):
    if (cents >= 25):
        cents -= 25
        coins += 1
    elif (cents >= 10):
        cents -= 10
        coins += 1
    elif (cents >= 5):
        cents -= 5
        coins += 1
    else:
        cents -= 1
        coins += 1

print(f"Change owed: {coins} ")
