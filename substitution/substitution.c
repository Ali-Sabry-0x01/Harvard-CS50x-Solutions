#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_key_validity(string s);
string get_encrypted(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (check_key_validity(argv[1]) == 1)
    {
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:  ");
    string ciphertext = get_encrypted(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

int check_key_validity(string s)
{
    int len = strlen(s);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < len; j++)
        {
            if (tolower(s[i]) == tolower(s[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

string get_encrypted(string text, string key)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            int index = tolower(text[i]) - 'a';
            if (isupper(text[i]))
            {
                text[i] = toupper(key[index]);
            }
            else
            {
                text[i] = tolower(key[index]);
            }
        }
    }
    return text;
}
