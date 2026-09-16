def get_height():
    while True:
        try:
            height = int(input("Height : "))
            if 1 <= height <= 8:
                return height
            else:
                print("Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
height = get_height()
for i in range(height):
    print(" " * (height - i - 1) + "#" * (i + 1))
