# 学习进度

更新：2026-10-07。

## 已完成的学习版作品

- Week 2 Scrabble：数组查询、字符遍历、大小写处理、函数参数与返回值、得分比较。原名 cash/score.c，现为 cs50/week02/scrabble/scrabble.c。
- Week 2 Readability：分别统计字母/单词/句子，浮点除法、Coleman–Liau 公式、round 和分支输出。
- Week 2 Caesar：已完成当前学习版并归档到 cs50/week02/caesar/caesar.c；练习 argc/argv、isdigit、atoi、取模、大小写分支和字符位移。编译成功，10 组本机检查通过 7 组，仍需修正边界行为。
- Week 1 Mario More：嵌套循环、双金字塔、1–8 高度输入校验。
- Week 1 Cash：25、10、5、1 分硬币的整除与取余。
- C 基础：Hello World、金额相减练习。

上述为学习实现和本机样例检查记录，不代表官方验收通过。SQL 目录只是已有材料，完成情况未确认。

## 待巩固与后续自行改进

- Scrabble 仍打印两个分数，胜负提示是 A win! / B win! / equal；后续提交课程前自行核对输出要求。
- Mario 每行右侧仍有空格；Cash 尚未拒绝负数输入，且使用中文结果提示。
- Readability 当前按空格数加一计算单词；可以自己思考空输入和连续空格的行为。
- Caesar：密钥 3、26、29 的样例及缺参、字母密钥、负数密钥检查通过；密钥 13 输入 xyz XYZ、密钥 25 输入 abc xyz 的小写回绕失败。原因是先将加法结果存回 char，再判断是否超过 z，当前 Mac 的有符号 char 发生转换；需先在 int 中完成计算或用相对字母位置取模，再写回字符。
- Caesar：空字符串密钥未被拒绝；atoi 对超大整数的处理也需自行检查，当前未测试该情形。课程提交前还需核对提示和输出格式；未运行 check50/style50。
- 继续巩固“遍历 → 判断 → 计数/累加”、整数与浮点除法、函数拆分。
- 工具习惯：进入对应题目目录；修改后重新 make；运行测试；Git 保存版本。

2026-10-07 本次归档保留所有 C 源码原样，未运行 check50/style50。
下一步：自行修正 Caesar 边界问题并复测；完成下一题后按 notes/git-workflow.md 保存版本。
