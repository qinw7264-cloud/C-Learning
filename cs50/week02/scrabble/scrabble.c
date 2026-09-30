#include<cs50.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>
int compute_score(string word);
int main(void)
{
    string A = get_string("PlayerA word?\n");
    string B = get_string("PlayerB word?\n");

    int a = compute_score(A);
    int b = compute_score(B);
    if(a > b)
    {
        printf("A win!\n");
    }    else if (a < b)
    {
        printf("B win!\n");
    }else
    {
        printf("equal");
    }
    


}




int compute_score(string word)
{
    int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };
    int score = 0;
    for(int i = 0;i < strlen(word); i++)
    {
       
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
           score = score + POINTS[word[i] - 'A'];
        }else if(word[i] >= 'a' && word[i] <= 'z')
        {
            score = score + POINTS[word[i] - 'a'];
        }
       
    }
     printf("%d\n",score);
     return score;

    
}