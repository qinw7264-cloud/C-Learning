#include<stdio.h>
#include<cs50.h>
int main(void)

{
    int h;

    do{
        h = get_int("Height?");

    }while(h < 1 || h > 8);

    for (int i = 1; i <= h; i++)
    {
        for (int j = 0;j < h - i; j++)
        {
            printf(" ");
        }
        for(int k = 0;k < i; k++)
        {
            printf("#");
        }
        printf(" ");
        printf(" ");
        for(int l = 0;l < i; l++)
        {
            printf("#");
        }
        for(int m = 0;m < h-i; m++)
        {
            printf(" ");
        }
        printf("\n");
    }
        
 }