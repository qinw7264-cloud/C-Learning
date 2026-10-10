#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 最多允许 9 名候选人
#define MAX 9

// 定义候选人类型
typedef struct
{
    string name;
    int votes;
}
candidate;

// 存储所有候选人
candidate candidates[MAX];

// 实际候选人数
int candidate_count;

// 函数声明
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // 检查是否输入了候选人
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // 初始化候选人
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // 获取选民人数
    int voter_count = get_int("Number of voters: ");

    // 依次获取每个选民的投票
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // 输出获胜者
    print_winner();
}

// 处理投票
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// 输出获胜者
void print_winner(void)
{
    int max = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
