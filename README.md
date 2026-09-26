# C 与 CS50 学习记录

以后在 VS Code 打开整个 `/Users/yc/Documents/C-Learning` 或原有 `CS50.code-workspace`。
**只编辑下列整理后的练习副本**，根目录 `mario.c`、`hello.c` 与 `cash/` 是保留的旧文件。

```text
C-Learning/
├── cs50/week01/
│   ├── mario-more/mario.c  # 双金字塔
│   └── cash/cash.c        # 硬币找零
├── c-basics/
│   ├── hello/hello.c      # 来自原 mooc 文件夹
│   └── change/change.c    # 原根目录 hello.c，实际是金额相减练习
├── sql/                  # 原有第 7 周练习，保持原位置
├── notes/                # 进度、文件来源与 Git 操作说明
├── .vscode/              # 原有编辑、编译和调试配置
└── CS50-使用说明.md        # 原有本机环境说明
```

## 编译并运行

```sh
cd /Users/yc/Documents/C-Learning
source .cs50/activate.sh
cd cs50/week01/mario-more
make mario
./mario
```

Cash 同理，在 `cs50/week01/cash` 中执行 `make cash`、`./cash`。
`.cs50` 和 `.venv` 留在本机、不纳入 Git。换电脑需要重新安装依赖，现有环境说明描述的是本机配置。
新练习放入 `cs50/week02/题目名/` 等目录；若生成新名称的无扩展名程序，把该程序名称加入 `.gitignore`，或统一输出到 `build/`。

Git 记录源码和说明，不记录可重新生成的程序、调试文件、环境依赖与课程数据库。
参见 `notes/git-workflow.md` 与 `notes/progress.md`。
