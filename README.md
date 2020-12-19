# minishell

The purpose of this project is to build a simple shell.
This implementation is based on GNU bash v4.4.20.

## Supported features

### Builtins
| command | options | long options |
|---------|---------|--------------|
| cd      |         | --help       |
| echo    | -n      |              |
| env     |         | --help       |
| exit    |         | --help       |
| export  |         | --help       |
| pwd     |         | --help       |
| unset   |         | --help       |

### Operators
- ```#``` comment
- ```;``` commands separation
- quoting with ```'``` and ```"```
- ```\``` escaping character
- ```*``` wildcard pattern matching
- ```|``` pipe
- ```<``` standard input
- ```<<``` heredoc input
- ```>``` standard output
- ```>>``` appending output
- ```&&``` and ```||``` with parenthesis for priorities (subshells are not supported with parenthesis)

### Signals
- **Ctrl+C**
- **Ctrl+D** (partial because of line buffering)
- **Ctrl+\\**

### Special parameters
- ```$VAR``` environment variables expansion (without ```$IFS``` word splitting during word expansion)
- ```$?``` exit status of the last command

## Documentation
### Building from source
```shell
git clone https://github.com/ChuOkupai/minishell.git
cd minishell
make
```
### Unit tests
Tests are located in *test* and can be launched with the command:
```shell
cd ./test
bash ./check.sh
```
Bonus tests can be enabled by setting the variable **$ENABLE_BONUS** to **1** (already enabled by default).

### Additional informations
- The makefile uses wildcards which do not respect the rules established by 42's norm.
- Information about usage and version can be displayed with:
```shell
./minishell --help
```
