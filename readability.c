#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int l_count = 0;
    int w_count = 1;
    int s_count = 0;

//count words, letters and sentences
    for (int i = 0; i < strlen(text); i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           l_count++;
       }
       else if (text[i] == ' ')
       {
           w_count++;
       }
       else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
       {
           s_count++;
       }
    }
//    Compute the index

    float index = 0.0588 * (100 * (float) l_count / (float) w_count) - 0.296 * (100 * (float) s_count / (float) w_count) - 15.8;
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}