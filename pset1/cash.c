#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float money;
    do{
     money=get_float("ENTER THE AMOUNT OF MONEY:");
    } while (money<0.0);

    int cents = round(money * 100);
    printf("%i \n",cents);

    int coins=0;


    while((cents-25)>=0)
    {
        cents=cents-25;
        coins++;
    }
    while((cents-10)>=0)
    {
        cents=cents-10;
        coins++;
    }
    while((cents-5)>=0)
    {
        cents=cents-5;
        coins++;
    }
    while((cents-1)>=0)
    {
        cents=cents-1;
        coins++;
    }

    printf("%i \n",coins);

}