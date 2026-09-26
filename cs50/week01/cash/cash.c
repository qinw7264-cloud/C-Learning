#include<stdio.h>
#include<cs50.h>

int main(void)
{
int c = get_int("Change owed:");
int quarters = c / 25;
c %= 25;
int dimes = c / 10;
c %= 10;
int nickels = c / 5;
c %= 5;
int pennies = c / 1;
printf("需要%d个硬币\n", quarters + dimes + nickels + pennies);


}



