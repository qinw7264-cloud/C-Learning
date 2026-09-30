# 每完成一个练习怎样存档

保存编辑器中的文件，编译并运行，试正常输入和边界输入，再从学习目录运行：

```sh
cd /Users/yc/Documents/C-Learning
git status
git diff
# 下面以修改 Cash 为例；换成这次实际修改的文件路径
git add cs50/week01/cash/cash.c notes/progress.md
git diff --cached
git commit -m "完善 Cash：增加输入校验"
```

- `status`：看哪些文件改变了。
- `diff`：看改了哪些行。
- `add`：选择这次要存档的文件；它还没有上传任何内容。
- `diff --cached`：确认本次存档内容，避免加入二进制或私密文件。
- `commit`：在本机建立一个有说明的版本，即使离线也能用。
- `git log --oneline`：查看过去的存档。
- 连接远程仓库后，`git push` 才会上传备份。

不必学完一整周才提交：每完成一个小功能、修复一个问题，都可以提交。测试未通过也能存档，但提交说明和进度中要写清状态。

## 首次连接 GitHub（尚未配置远程时）

本地 Git 与 GitHub 登录是两件事。本次检查：仓库没有远程地址，Mac 未安装 gh；已连接的 GitHub 插件没有返回可用仓库。
可先在 GitHub 网页创建一个空的 **Private** 仓库（不要勾选初始化 README），再运行：

```sh
cd /Users/yc/Documents/C-Learning
git remote add origin https://github.com/qinw7264-cloud/c-cs50-learning.git
git push -u origin main
```

上述地址要求新仓库名为 c-cs50-learning；若使用其他名称，请替换地址。
首次推送需要 GitHub 身份验证，可使用凭据管理器或个人访问令牌，不能用账户密码代替令牌。

也可以先安装 GitHub CLI，再运行：

```sh
gh auth login
cd /Users/yc/Documents/C-Learning
gh repo create c-cs50-learning --private --source=. --remote=origin --push
```

若同名仓库已存在，应先确认其内容再决定连接，避免覆盖。已设置 origin 时不要重复创建仓库；用 `git remote -v` 查看，用 `git push` 更新。
