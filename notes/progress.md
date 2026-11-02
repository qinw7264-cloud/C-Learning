# 学习进度

更新：2026-10-10。

## 已完成的学习版作品

- Week 3 Plurality：已整理到 cs50/week03/plurality/plurality.c；练习结构体数组、strcmp、bool 返回值、全局变量、两次遍历寻找所有最高票者。2026-10-10 使用本机 CS50 库编译，正常投票、平票、全部无效票三组检查通过；全无效票时所有候选人以 0 票并列输出。未运行官方 check50/style50。

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

2026-10-10 Plurality 从 week02/caesar/candidate.c 整理到 Week 3 目录，仅统一缩进，保留算法。待巩固：struct、全局变量与函数调用的数据访问关系。可展示作品：支持无效票判断和并列获胜者的命令行投票程序。后续学习 Runoff 前先理解选举规则。

## 2026-10-31：Week 4 Volume 准备开始

- 官方 2026 原始作业已导入 `cs50/week04/volume/`，包含 `volume.c` 与 `input.wav`；待填写代码保持原样，尚未完成作业。
- 题目：https://cs50.harvard.edu/x/psets/4/volume/
- 来源：https://cdn.cs50.net/2026/x/psets/4/volume.zip
- 学习目标：二进制文件读写、44 字节 WAV 文件头、16 位音频采样与音量缩放。当前掌握情况待练习确认。
- 编译产物与生成的 WAV 输出已加入忽略规则，官方输入音频保留。

## 2026-10-31：Week 4 Filter 基础版准备开始

- 下一题有基础版与挑战版，本次默认导入基础版 `cs50/week04/filter-less/`。
- 官方 2026 原始文件保持原样，包含 helpers.c、helpers.h、filter.c、bmp.h、Makefile 与 images/ 中的四张示例图片；尚未实现滤镜。
- 题目：https://cs50.harvard.edu/x/psets/4/filter/less/
- 来源：https://cdn.cs50.net/2026/x/psets/4/filter-less.zip
- 官方骨架已在临时目录通过本机 make filter 编译，未进行作业正确性验收。
- 学习目标：RGB 像素、结构体、二维数组、灰度、怀旧、水平翻转和模糊；掌握情况待练习确认。可展示作品目标：命令行图片滤镜工具。
- 在本题目录运行 make filter，将 filter.c 与 helpers.c 一起编译；主要填写 helpers.c。例如完成灰度后运行 ./filter -g images/yard.bmp output.bmp。
- 程序、题目目录根部生成的 BMP 与 output/ 已忽略，官方 images/ 示例保留。

## 2026-11-02：完成 CS50x Week 4

- 完成 Volume：能够复制 WAV 文件头、逐个读取 16 位采样并按倍率调整音量。用倍率 1 生成的文件与原始输入逐字节一致。
- 完成 Filter (Less)：实现灰度、怀旧、水平翻转和模糊四种滤镜；四种模式均在示例 BMP 上运行成功。
- 完成 Recover：独立梳理 512 字节块、JPEG 文件头识别、文件切换与连续写入逻辑，从 `card.raw` 成功恢复 50 张 JPEG。
- 本次三个程序均通过 `-Wall -Wextra -Werror` 编译检查。可展示作品：命令行音量调整器、图片滤镜工具、存储卡照片恢复工具。
- 关键进步：面对较长流程时，已经能自己拆分状态与分支并把整条逻辑串起来。待巩固：二进制 I/O 返回值检查、格式化与边界条件，以及把重复的本机验证整理成更系统的测试。
