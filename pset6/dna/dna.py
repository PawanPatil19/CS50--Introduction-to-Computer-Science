from sys import argv,exit
import csv
from csv import reader, DictReader


def main():
    if len(argv)<3: #checking for argument count
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    with open(argv[1],newline='') as database: #reading and knowing the types of dna to be found
        db = reader(database)
        dnatype=next(db)
        dnatype.pop(0)


    sequence=open(argv[2],"r") # reading the sequence file and storing its contents
    sq=sequence.read()
    l=len(sq)
    sequences={}
    for dna in dnatype:
        sequences[dna]=1

    for key in sequences:
        l_dna=len(key)
        count=0
        count_max=0
        for j in range(l):
            while count > 0:
                count -= 1
                continue


            if sq[j:j+l_dna]==key:
                while sq[j:j+l_dna] == sq[j+l_dna:j+l_dna+l_dna]:
                    count=count+1
                    j=j+l_dna

                if(count>count_max):
                    count_max=count

        sequences[key]+=count_max



    with open(argv[1],newline='') as database: #reading and knowing the types of dna to be found
        db = DictReader(database, delimiter=',')
        for person in db:
            p=0
            for gene in sequences:
                if sequences[gene]==int(person[gene]):
                    p=p+1
            if p==len(sequences):
                print(person['name'])
                exit(0)
        if p!=len(sequences):
            print("No match")




main()


























