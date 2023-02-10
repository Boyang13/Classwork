# TODO
from cs50 import get_string
from math import floor

AE1 = "34"
AE2 = "37"
MC1 = "51"
MC2 = "52"
MC3 = "53"
MC4 = "54"
MC5 = "55"
Visa = "4"
type = "INVALID"

# get and clean the input from the user
number = get_string("Number: ")
number = number.strip()
count = len(number)

# conditions to determine card is which type
# all visa cards begin with 4
# same format for other cards
if (count == 13):
    if (number[:1] == Visa):
        type = "VISA"

elif (count == 15):
    if (number[:2] == AE1 or number[:2] == AE2):
        type = "AMEX"

elif (count == 16):
    if (number[:2] == MC1 or number[:2] == MC2 or number[:2] == MC3 or number[:2] == MC4 or number[:2] == MC5):
        type = "MASTERCARD"

    elif (number[:1] == Visa):
        type = "VISA"

if (type != "INVALID"):
    number = int(number)
    last = 0
    tempx = 0
    secToLast = 0

# if the sum of alternate digits starting at second to last times two and the other digits = 0, the card is valid
# had to research Luhn's algorithm
    while (number > 0):
        last += number % 10

        number /= 10
        number = floor(number)

        tempx = (number % 10) * 2

        if (tempx >= 10):
            secToLast += tempx % 10
            tempx /= 10
            secToLast += floor(tempx)

        else:
            secToLast += tempx

        number /= 10
        number = floor(number)
# final sum
    if ((last + secToLast) % 10 == 0):
        print(type)

    else:
        print("INVALID")
else:
    print(type)
