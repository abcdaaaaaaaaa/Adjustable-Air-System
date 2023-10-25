import csv

data_list = []
data_number = 1
mode = input("Do you want to (a)dd data or (w)rite data to a new file? (a/w): ")
    
while True:
    print(f"Data {data_number}:")
    usvhr = input("usV/hr: ")

    data_entry = {
        'usV/hr': usvhr,
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (y/n): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('GeigerCounter.csv', mode, newline='') as file:
    fieldnames = ['usV/hr']
    writer = csv.DictWriter(file, fieldnames=fieldnames)

    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)
     
print("Data has been successfully written to the CSV file")
