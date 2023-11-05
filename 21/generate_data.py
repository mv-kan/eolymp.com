import random

N = 100000
P = 5
print("100000 5")
# Open a file in write mode
file_name = "input_rand.txt"
with open(file_name, 'w') as file:
    # Write data to the file
    file.write("100000 5\n")
    for i in range(100000):
        file.write(f"{random.randint(0, 100)} ")