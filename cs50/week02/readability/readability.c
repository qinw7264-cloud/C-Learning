#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("input\n");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }else if(grade >= 16)
    {
        printf("Grade 16+\n");
    }else
    {
        printf("Grade %d", grade);
    }
}    

int count_letters(string text)
{
    int letters = 0;
     for (int i = 0, n = strlen(text); i < n; i++)
   {
    if(isalpha(text[i]))
    {
        letters++;
    }
   }
   return letters;
}

int count_words(string text)
{
    int words = 1;
   
    for(int i = 0,n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
        words++;
        }
    }
   return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
         sentences++;
        }
    }
    return sentences;
}