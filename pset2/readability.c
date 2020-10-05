#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{

  string text=get_string("Text:");



  int len=strlen(text);
  char b=' ';
  int index;
  double count=0;
  double words=1;
  double sentence=0;
  char c='!';
  char d='.';
  char e='?';
  string f="'";
  char *str = "'";
  char g=',';

  for(int i=0;i<len;i++)
  {

      char a = text[i];


      if(a==b)
      {

          words++;
      }
      else if((a==c) || (a==d) || (a==e) )
      {
          sentence++;
      }

      else if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
      {
        count++;
      }
      else
      {

      }


  }


        double L=(count/words)*100;
        double S=(sentence/words)*100;
        index = round((0.0588 * L) - (0.296 * S) - 15.8);

        if(index<1)
        {
          printf("Grade: Before Grade 1\n");
        }
        else if(index>16)
        {
          printf("Grade 16+\n");
        }
        else
        {
          printf("Grade %i\n",index);
        }


}