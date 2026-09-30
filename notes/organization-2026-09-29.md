# 2026-09-29 整理记录

- 整理前完整快照（含 Git、依赖、编译产物）：`.local-backups/20260929-212305/before-organization.tar.gz`。
- 根目录旧文件与原 cash 文件夹完整保留在 `.local-backups/20260929-212305/originals/`，包括空的 compute_score/score.c。
- cash/score.c 按实际题目命名为 cs50/week02/scrabble/scrabble.c；Readability 移入独立题目目录。
- 所有练习 C 源码逐字节保留；SHA-256 和来源见 source-manifest.json。
- 延续已有 main 分支及提交历史；沿用 week01/week02 命名。
- 原 mooc/hello.c 未改动，SQL 材料保持原位置。
- 备份目录被 Git 忽略并在 VS Code 中隐藏。不要继续编辑备份中的旧代码。

## 验证结果

- Scrabble 和 Readability 均使用现有 CS50 编译环境成功编译。
- Scrabble：相同得分、第二位获胜、第一位获胜、大小写等价，共 4 组样例通过。
- Readability：One fish → Before Grade 1；Congratulations → Grade 3；Computational complexity → Grade 15，共 3 组样例通过。
- 6 份学习源码均与来源记录 SHA-256 一致；未改代码逻辑或格式。
- 编译产物及备份被 Git 忽略，题目源码正常跟踪。
- 本次未运行官方 check50/style50。
