from cs50 import get_int
l=0

while (l>8 or l<1):
    l=get_int("Height: ")


for i in range(l):
    for j in range(l,i+1,-1):
        print(" ",end="")
    for p in range(0,i+1,1):
        print("#",end="")
    print("  ",end="")
    for q in range(0,i+1,1):
        print("#",end="")
    print()







