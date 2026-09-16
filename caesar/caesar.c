#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
string get_encrypted(string , int);
int main (int argc , string argv[])
{
    if(argc!=2)
    {
       printf("Usage: ./caesar key\n");
       return 1;
    }
    string key = argv[1];
    int valid = 1;
    for(int i = 0, len = strlen(key); i<len ; ++i)
    {
        if (!isdigit(key[i]))
        {
            valid = 0;
        }
    }
        if(valid ==1)
        {
          int k = atoi(key);
          if(k<0)
          {
            printf("Usage: ./caesar key\n");
            return 1;
          }
           string p = get_string("plaintext:  ");
           string c = get_encrypted(p , k);
           printf("ciphertext: %s\n" ,c);
           return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
string get_encrypted(string before , int k)
{
    for (int i =0 , len = strlen(before) ; i<len ; ++i)
    {
        if(before[i] >= 'A' && before[i] <= 'Z')
        {
        before[i]-='A';
        before[i] = (before[i] + k)%26;
        before[i]+='A';
        }
        else if(before[i] >= 'a' && before[i] <= 'z')
        {
        before[i]-='a';
        before[i] = (before[i] + k)%26;
        before[i]+='a';
        }
    }
    string after = before;
    return after;
}
