#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int get_score(string);
int main (void)
{
   string text = get_string("Text: ");
   int score = get_score(text);
   if(score < 1)
   {
     printf("Before Grade 1\n");
   }
   else if (score >= 16)
   {
    printf("Grade 16+\n");
   }
   else
   {
    printf("Grade %i\n" , score);
   }
   return 0;
}
int get_score(string s)
{
   int letters = 0;
   int sentenses = 0;
   int  words = 1;
   for (int i = 0,len = strlen(s) ; i<len ;  i++ )
   {
    if(isupper(s[i]))
    {
        letters+=1;
    }
    else if(islower(s[i]))
    {
        letters+=1;
    }
    else if (s[i]==' ')
    {
        words+=1;
    }
    else if (s[i]=='?' || s[i]=='!' || s[i]=='.')
    sentenses+=1;
   }
   float L = (letters/(float)words)*100;
   float S = (sentenses/(float)words)*100;
   float index = 0.0588 * L - 0.296 * S - 15.8;
   int score = round(index);
   return score;
}
