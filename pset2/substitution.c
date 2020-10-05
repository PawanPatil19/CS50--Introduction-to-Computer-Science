#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_validkey(string key);

int main(int argc, string argv[])
{

    if (argc == 2 && isalpha(*argv[1]))

    {
        string key=argv[1];
        int validation= get_validkey(argv[1]);

        if(validation==1)
        {
            return 1;
        }
        else

        {

        string s = get_string("plaintext: ");
        printf("ciphertext:");

        int len=strlen(s);
        string c;

        for(int i=0; i<len;i++)
        {

            if (s[i] >= 'a' && s[i] <= 'z')
            {

                 char a=s[i];
                 int asc=a-97;
                 char b=key[asc];
                 char x=tolower(b);
                 printf("%c",x);
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {

                 char a=s[i];
                 int asc=a-65;
                 char b=key[asc];
                 char x=toupper(b);
                 printf("%c",x);
            }

            else
            {

                printf("%c", s[i]);

            }

        }
        printf("\n");
        return 0;
        }
    }



    else
    {
            printf("Usage: ./substitution\n");
            return 1;
    }


}

int get_validkey(string key)
{
    int inputlength = strlen(key);
    if (inputlength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {

        for (int g = 0; g < 26; g++)
        {

            if (key[g] < 'A' || (key[g] > 'Z' && key[g] < 'a') || key[g] > 'z')
            {
                printf("Usage: ./substitution\n");
                return 1;
            }

            for (int k = (g - 1); k >= 0; k--)
            {
                if (key[k] == key[g])
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }

                if (key[k] == key[g] + 32)
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }
                if (key[k] == key[g] - 32)
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }
            }

            for (int l = (g + 1); l < 26; l++)
            {
                if (key[l] == key[g])
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }
                if (key[l] == key[g]  + 32)
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }
                if (key[l] == key[g] - 32)
                {
                    printf("Usage: ./substitution\n");
                    return 1;
                }
            }

        }
        return 0;
    }

}