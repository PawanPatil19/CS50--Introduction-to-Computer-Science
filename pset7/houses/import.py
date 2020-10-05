import csv
from sys import argv, exit
from cs50 import SQL



if len(argv) != 2:
    print("missing command-line argument")
    exit(1)
db = SQL("sqlite:///students.db")
with open(argv[1],"r") as characters:
    reader=csv.DictReader(characters,delimiter=",")



    for row in reader:


        name=row["name"]
        name_list=name.split()
        if(len(name_list)==3):
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)",name_list[0] ,name_list[1], name_list[2], row["house"], row["birth"] )
        elif(len(name_list)==2):
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)",name_list[0] , None, name_list[1], row["house"], row["birth"] )
exit(0)



