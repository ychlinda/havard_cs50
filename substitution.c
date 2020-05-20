#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Based on codes from teeschorle

bool validate(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        if (validate(key) == true)

        {
            string plaintext = get_string("plaintext: ");

            int charcount = strlen(plaintext);
            char ciphertext[charcount];
            string abc = "abcdefghijklmnopqrstuvwxyz";


            for (int i = 0; i < charcount; i++)
            {
                if (isupper(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {

                        if (abc[j] == tolower(plaintext[i]))

                        {
                            ciphertext[i] = toupper(key[j]);
                        }
                    }
                }

                else if (islower(plaintext[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (abc[j] == plaintext[i])
                        {
                            ciphertext[i] = tolower(key[j]);
                        }
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }

            ciphertext[charcount] = '\0';

            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            printf("Please make sure your key consists of 26 characters. \n");
            return 1;
        }
    }
    else
    {
        printf("Please provide an alphabetical key.\n");
        return 1;
    }
}

bool validate(string key)
{
    int checks = 0;
    if (strlen(key) == 26)

    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    checks++;
                    break;
                }
            }
        }

        if (checks== 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

