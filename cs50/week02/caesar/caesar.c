#include<stdio.h>
#include<cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string key = argv[1];
     
    for(int i = 0, n = strlen(key); i < n; i++)
    {
       if(!isdigit(key[i]))
       {
        printf("Usage: ./caesar key\n");
        return 1;
       }
    }
    int k = atoi(key);
    k = k %26;
    string text = get_string("text?\n");
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isupper(text[i]))
        {
            text[i] = text[i] + k;
            if(text[i] > 'Z')
            {
                text[i] -= 26;
            }
        }
        else if(islower(text[i]))
        {
            text[i] = text[i] + k;
            if(text[i] > 'z')
            {
                text[i] -= 26;
            }
        }
       
    }
    printf("%s\n", text);
    return 0;
}