#include <stdio.h>
int main()
{
    int price = 0;
    int amount = 0;

    printf("请输入金额：");
    scanf("%d", &price);
    printf("请输入票面：");
    scanf("%d", &amount);

    int change = amount - price;
    printf("找零金额为：%d\n", change);


    return 0;
}
