from cs50 import get_string
from cs50 import get_int

text=get_string("Text: ")

lent=len(text)
b=' '
count=0
words=1
sentence=0
c='!'
d='.'
e='?'
f="'"
st = "'"
g=','

for i in range(0,lent,1):
    a = text[i]
    if(a==b) :
        words=words+1

    elif((a==c) or (a==d) or (a==e) ):
        sentence=sentence+1

    elif ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        count=count+1




L=(count/words)*100
S=(sentence/words)*100
index = round((0.0588 * L) - (0.296 * S) - 15.8)


if (index<1):
    print("Grade: Before Grade 1")
elif (index>16):
    print("Grade 16+")
else :
    print(f"Grade {index}")


