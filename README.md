# C 与 CS50 学习记录

在 VS Code 打开整个 `/Users/yc/Documents/C-Learning` 或 `CS50.code-workspace`。
以后只在 `cs50/`、`c-basics/` 中编辑 C 练习，每道题一个文件夹。

```text
C-Learning/
├── cs50/
│   ├── week01/
│   │   ├── mario-more/mario.c
│   │   └── cash/cash.c
│   └── week02/
│       ├── scrabble/scrabble.c
│       └── readability/readability.c
├── c-basics/
│   ├── hello/hello.c
│   └── change/change.c
├── sql/                      # 第 7 周材料，完成情况未确认
├── notes/                    # 进度、来源、整理记录、Git 说明
├── .vscode/                  # 编译与调试配置
├── .local-backups/            # 本机快照和原文件，已隐藏，不提交
└── CS50.code-workspace
```

## 编译并运行

在 VS Code 的新终端中已有编译环境；普通终端先加载一次：

```sh
cd /Users/yc/Documents/C-Learning
source .cs50/activate.sh
cd cs50/week02/scrabble
make scrabble
./scrabble
```

Readability 在 `cs50/week02/readability` 中运行 `make readability` 和 `./readability`。
终端按 ↑ 可以复用命令；输入文件名前几位后按 Tab 可以补全。
`.cs50` 和 `.venv` 是本机依赖，不纳入 Git。换电脑需重新配置，见 `CS50-使用说明.md`。

## 当前进度

Week 2 Scrabble 与 Readability 已完成学习版实现，并做本机样例检查；未运行官方 check50/style50。
Scrabble 仍有分数调试输出及自定义胜负提示。现有待改进点见 `notes/progress.md`。

## Git

Git 的 commit 是本机版本快照；push 才是上传到远程仓库。
每完成一题，测试后保存一次提交。完整步骤见 `notes/git-workflow.md`。
程序、调试文件、依赖和旧备份被忽略；新题生成新的程序名称时，将程序名加入 `.gitignore`，
并用 `!题目名/` 保留同名源码目录，或把编译产物统一输出到 `build/`。

本次整理来源和备份位置见 `notes/organization-2026-09-29.md`。
