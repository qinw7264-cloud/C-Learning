# 2026-10-07 Caesar 归档记录

- 主文件已位于 cs50/week02/caesar/caesar.c，无需移动；源码按用户当前学习版逐字节保留。
- 搜索 Documents、Desktop、Downloads 和 mooc 下的 caesar.c，只发现主文件与旧版备份。
- 旧版未完成源码和旧程序保留于 .local-backups/20260929-212305/originals/cash/；旧 cash 目录已不存在，无需再次搬移。
- 原完整快照 before-organization.tar.gz 保留；查看压缩包目录未发现 Caesar 条目。
- 主源码与旧备份内容不同，分别记录 SHA-256 于 source-manifest.json，未删除或覆盖任何 C 源码、SQL 练习或原备份。
- 更新 .gitignore，忽略 caesar 可执行文件，保留 caesar/ 源码目录；现有 *.dSYM/ 和 .local-backups/ 规则继续适用。
- 更新 README、学习进度、来源记录和最简 Git 流程。

## 本机验证

使用现有 CS50 头文件和库在临时目录编译当前源码，编译成功，未覆盖原有程序。
10 组运行检查通过 7 组：

- key=3，abcd efg!123 → defg hij!123。
- key=3，ABC XYZ abc xyz! → DEF ABC def abc!。
- key=26，ABC xyz!123 保持不变。
- key=29，Abc XYZ! → Def ABC!。
- 无参数、字母密钥 abc、负数密钥 -1 均返回 Usage 和状态码 1。

未通过的 3 组：

- key=13，xyz XYZ 应为 klm KLM，小写部分输出异常字节。
- key=25，abc xyz 应为 zab wxy，末尾小写部分输出异常字节。
- 空字符串密钥应被拒绝，当前却进入正文输入并返回 0。

本次按此前规则保留学习源码，问题记入 progress.md，未运行官方 check50/style50；归档完成不代表全部边界检查或官方验收通过。

## Git 状态

- 整理前：main 分支，HEAD=78569c5，仅 Caesar 源码及可执行文件未跟踪，暂存区为空。
- 延续现有 Git 历史，本次只提交 Caesar 源码及相关归档说明、忽略规则；可执行文件和备份不提交。
- git remote -v 为空，未配置远程，因此本次仅保存本机 commit，不执行 push，也不创建或猜测远程仓库。
