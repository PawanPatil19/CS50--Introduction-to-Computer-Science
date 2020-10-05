from sys import argv, exit
from cs50 import SQL


db = SQL("sqlite:///students.db")
if len(argv) != 2:
    if sys.argv[1] != "Gryffindor" or sys.argv[1] != "Slytherin" or sys.argv[1] != "Hufflepuff" or sys.argv[1] != "Ravenclaw":
        print("missing command-line argument")
        exit(1)

data={}
data=db.execute("SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last ASC, first ASC ", argv[1])

for row in data:

    if row["middle"] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")

exit(0)

