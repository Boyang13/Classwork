from cs50 import get_int

height = 0
while (height > 8 or height < 1):
    height = get_int("Height:\n")

for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * i, end="  ")
    print("#" * i)


# so I can use get int
# sets limit on height
# uses get int to get height
# prints the mario obstacle
