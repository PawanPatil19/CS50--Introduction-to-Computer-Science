#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do{
        height=get_int("Height");
    } while (height <= 0 || height >8);



    for(int i=1; i<=height; i++)
    {
        for(int a=height; a>i; a--)
        {
            printf(" ");
        }

        for(int b=1; b<=i; b++)
        {
            printf("#");
        }

        printf("  ");

        for(int x=1 ; x<=i ; x++)
            {
                 printf("#");

            }
        printf("\n");
    }
}