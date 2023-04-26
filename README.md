# 0x16。 C - 简单外壳 <br/>
`C`
`小组项目`
`系统调用`

# 简单的 Shell 项目

用 C 编写的简单 Unix shell 实现。

＃＃ 特征
- 执行用户输入的命令
- 支持基本的命令行语法和 shell 内置命令
- 允许命令历史和自定义配置选项
- 处理信号和管理后台进程

＃＃ 安装

要编译该程序，请使用以下命令：

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```


## 用法
要启动 shell，只需运行 `hsh` 可执行文件：

```
$./hsh
```


应显示 shell 提示符，您可以像往常一样输入命令。 使用 exit 命令或按 Ctrl-D 退出 shell。

## 内置命令
shell 中内置了以下命令：

- `cd`: 改变工作目录
- `history`：显示最近的命令列表
- `help`：显示有关 shell 及其内置命令的信息
- `setenv`: 设置环境变量的值
- `unsetenv`: 取消设置环境变量
- `env`: 显示当前环境变量
- `exit`: 退出 shell

## 配置选项
可以使用以下配置选项自定义 shell：

- `PROMPT`：要显示的 shell 提示符（默认为“$”）
- `HISTORY_FILE`：要使用的历史文件的名称（默认为 `~/.simple_shell_history`）
- `MAX_HISTORY`：历史记录中存储的最大命令数（默认为 `4096`）</br>
这些选项可以使用 setenv 命令设置，并将保存到配置文件中以供将来使用。

## 例子
以下是如何使用 shell 的一些示例：

```

$./hsh
$ ls -l
共 16 个
-rw-r--r-- 1 用户用户 27 Apr 26 14:12 hello_world.c
-rwxr-xr-x 1 用户 user 8096 Apr 26 14:12 hsh
$光盘..
$密码
/家/用户
$帮助
Simple Shell - 一个简单的 Unix shell 实现

内置命令：
cd [directory] 改变当前工作目录
history 显示命令历史
help 显示此帮助信息
setenv [variable] [value] 设置环境变量
unsetenv [variable] 取消设置环境变量
env 显示环境变量
exit 退出外壳

配置选项：
PROMPT 要显示的 shell 提示符（默认为“$”）
HISTORY_FILE 要使用的历史文件（默认为 ~/.simple_shell_history）
MAX_HISTORY 历史中存储的最大命令数（默认为 4096）
$ 退出

```

## 作者
- [阿尔方斯.](https://github.com/alphonsi)
- [格雷厄姆.](https://github.com/olusiekwin)

## 致谢
以下代码已在研究和理解该项目中使用，并已得到适当归属：

<!-- Simple_Shell 作者 J. Smith (2019). [Holberton Shool]. GitHub. (https://github.com/arthurdamm/simple_shell.git) -->

## 执照
该项目根据 MIT 许可证获得许可 - 有关详细信息，请参阅许可证文件。
