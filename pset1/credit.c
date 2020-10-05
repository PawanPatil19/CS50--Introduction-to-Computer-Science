#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main(void)
{
        static int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
        static int sum1,sum2;
        long num=get_long("Number:");
        int len;
        len = strlen((String.valueOf(num)));
        string number = String.valueOf(num);

        if(len==16)
        {
        a = Character.getNumericValue(number.charAt(0));
        b = Character.getNumericValue(number.charAt(1));
        c = Character.getNumericValue(number.charAt(2));
        d = Character.getNumericValue(number.charAt(3));
        e = Character.getNumericValue(number.charAt(4));
        f = Character.getNumericValue(number.charAt(5));
        g = Character.getNumericValue(number.charAt(6));
        h = Character.getNumericValue(number.charAt(7));
        i = Character.getNumericValue(number.charAt(8));
         j = Character.getNumericValue(number.charAt(9));
         k = Character.getNumericValue(number.charAt(10));
        l = Character.getNumericValue(number.charAt(11));
         m = Character.getNumericValue(number.charAt(12));
        n = Character.getNumericValue(number.charAt(13));
         o = Character.getNumericValue(number.charAt(14));
         p = Character.getNumericValue(number.charAt(15));
        sum1=b+d+f+h+j+l+n+p;
        }

        else if(len==15)
        {
        a = Character.getNumericValue(number.charAt(0));
        b = Character.getNumericValue(number.charAt(1));
        c = Character.getNumericValue(number.charAt(2));
       d = Character.getNumericValue(number.charAt(3));
        e = Character.getNumericValue(number.charAt(4));
        f = Character.getNumericValue(number.charAt(5));
         g = Character.getNumericValue(number.charAt(6));
        h = Character.getNumericValue(number.charAt(7));
        i = Character.getNumericValue(number.charAt(8));
         j = Character.getNumericValue(number.charAt(9));
        k = Character.getNumericValue(number.charAt(10));
         l = Character.getNumericValue(number.charAt(11));
        m = Character.getNumericValue(number.charAt(12));
        n = Character.getNumericValue(number.charAt(13));
         o = Character.getNumericValue(number.charAt(14));
         p =0;
        sum1=b+d+f+h+j+l+n+p;
        }

        else if(len==13)
        {
       a = Character.getNumericValue(number.charAt(0));
         b = Character.getNumericValue(number.charAt(1));
        c = Character.getNumericValue(number.charAt(2));
         d = Character.getNumericValue(number.charAt(3));
         e = Character.getNumericValue(number.charAt(4));
         f = Character.getNumericValue(number.charAt(5));
       g = Character.getNumericValue(number.charAt(6));
         h = Character.getNumericValue(number.charAt(7));
         i = Character.getNumericValue(number.charAt(8));
         j = Character.getNumericValue(number.charAt(9));
         k = Character.getNumericValue(number.charAt(10));
        l = Character.getNumericValue(number.charAt(11));
         m = Character.getNumericValue(number.charAt(12));
         n=0;
         o=0;
        p=0;
        sum1=b+d+f+h+j+l+n+p;
        }


         string a1=Integer.toString(2*a);
         string a2=Integer.toString(2*c);
         string a3=Integer.toString(2*e);
         string a4=Integer.toString(2*g);
         string a5=Integer.toString(2*i);
         string a6=Integer.toString(2*k);
         string a7=Integer.toString(2*m);
        string a8=Integer.toString(2*o);


         String a9=a1.concat((a2.concat(a3.concat(a4.concat(a5.concat(a6.concat(a7.concat(a8))))))));

         int length=a9.length();

         for(int i=0; i<=(length-1); i++)
        {
            int a = Character.getNumericValue(a9.charAt(i));
            sum2 = a+sum2;
        }

         int tsum=sum1+sum2;




         if((tsum%10)==0)
         {
             if(len==15 && a==3 && (b==3 || b==7))
             {
                 System.out.println("American Express");
             }
             else if(len==16 && a==5 && (b==1 || b==2 || b==3 || b==4 || b==5))
             {
                 System.out.println("Mastercard");
             }
             else if((len==13 || len==16) && a==4)
             {
                 System.out.println("VISA");
             }
             else
             {
                 System.out.println("INVALID");
             }
         }
         else
         {


         }
}