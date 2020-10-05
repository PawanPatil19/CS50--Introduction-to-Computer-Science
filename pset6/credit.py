from cs50 import get_int
from cs50 import get_string
from sys import  exit


no=get_string("Number: ")
if no.isdigit() and len(no) < 13:
        print("INVALID")
        exit(0)

lent = len(no)
sum1=0
a9=""
if int(lent)==16:
    a = int(no[0])
    b = int(no[1])
    c = int(no[2])
    d = int(no[3])
    e = int(no[4])
    f = int(no[5])
    g = int(no[6])
    h = int(no[7])
    i = int(no[8])
    j = int(no[9])
    k = int(no[10])
    l = int(no[11])
    m = int(no[12])
    n = int(no[13])
    o = int(no[14])
    p = int(no[15])
    sum1=b+d+f+h+j+l+n+p
    a1=str(2*a)
    a2=str(2*c)
    a3=str(2*e)
    a4=str(2*g)
    a5=str(2*i)
    a6=str(2*k)
    a7=str(2*m)
    a8=str(2*o)
    a9=a1+a2+a3+a4+a5+a6+a7+a8


elif int(lent)==15:
    a = int(no[14])
    b = int(no[13])
    c = int(no[12])
    d = int(no[11])
    e = int(no[10])
    f = int(no[9])
    g = int(no[8])
    h = int(no[7])
    i = int(no[6])
    j = int(no[5])
    k = int(no[4])
    l = int(no[3])
    m = int(no[2])
    n = int(no[1])
    o = int(no[0])
    p = 0
    sum1=a+c+e+g+i+k+m+o
    a1=str(2*b)
    a2=str(2*d)
    a3=str(2*f)
    a4=str(2*h)
    a5=str(2*j)
    a6=str(2*l)
    a7=str(2*n)
    a9=a1+a2+a3+a4+a5+a6+a7



elif int(lent)==13:
    a = int(no[12])
    b = int(no[11])
    c = int(no[10])
    d = int(no[9])
    e = int(no[8])
    f = int(no[7])
    g = int(no[6])
    h = int(no[5])
    i = int(no[4])
    j = int(no[3])
    k = int(no[2])
    l = int(no[1])
    m = int(no[0])
    n = 0
    o = 0
    p = 0
    sum1=a+c+e+g+i+k+m+o
    a1=str(2*b)
    a2=str(2*d)
    a3=str(2*f)
    a4=str(2*h)
    a5=str(2*j)
    a6=str(2*l)
    a9=a1+a2+a3+a4+a5+a6


length=len(a9)

sum2=0
if(length!=0) :
    for i in range(0,int(length),1):
        ab = int(a9[i])
        sum2 = int(ab)+int(sum2)


tsum=0
tsum=int(sum1)+int(sum2)


if (tsum%10)==0 :
    if (lent==15 and int(no[0])==3 and (int(no[1])==4 or int(no[1])==7)) :
        print("AMEX")
    elif (lent==16 and int(no[0])==5 and (int(no[1])==1 or int(no[1])==2 or int(no[1])==3 or int(no[1])==4 or int(no[1])==5)):
        print("MASTERCARD")
    elif((lent==13 or lent==16) and int(no[0])==4) :
        print("VISA")
    else :
        print("INVALID")





