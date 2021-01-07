1. 算法竞赛中数组一般会声明得稍大一些。在空间够用的前提下，浪费一点不会有太大影响。

2. 比较大的数组尽量声明在 `main` 函数外，否则程序可能无法运行。

3. 数组 `a` 复制 `k` 个元素到数组 `b` ，如果是整型，复制操作为： `memcpy(b, a, sizeof(int)* k)` ，如果是浮点型，复制操作为： `memcpy(b, a, sizeof(double)*k)` 。使用 `memcpy` 函数要包含头文件 `string.h` 。如果把数组 `a` 全部复制到数组 `b` 中，可以直接写 `memcpy(b, a, sizeof(a))` 。

4. `memset(a, 0, sizeof(a))` 的作用是把数组 `a` 清零，也在 `string.h` 中定义。

5.  `C` 语言中的字符型用关键字 `char` 表示，它实际存储的是字符的 `ASCII` 码。字符常量可以用单引号法表示。语法上可以把字符当作 `int` 型使用。

6. 读入一个不含空格、 `TAB` 和回车符的字符串，存入字符数组 `s` ：`scanf("%s", s)` 。注意没有 `'&'` 。如果是字符串数组 `char s[maxn][maxn]` 则可以用 `scanf("%s", s[i])` 表示读取第 `i` 个字符串。遇到空白字符会停下来。

7. 可以用 `sprintf` 输出到字符串，应当保证字符串足够大（一般为字符的个数 `+ 1`），否则会溢出。用法：

   ```c 
   char s[20], buf[99];	//s为输入的字符串，buf为sprintf会输出到的字符串
   scanf("%s", s);	//读入字符串 s
   int abc = 111, de = 11;
   int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
   sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
   int ok = 1;
   for(int i = 0; i < strlen(buf); i++)
   {
       if(strchr(s, buf[i]) == NULL)
           ok = 0;
   }
   ```

8.  `strlen(s)` 的作用是获取字符串 `s` 的 **实际** 长度。`strlen(s)` 返回的是结束标记之前的字符个数。`s` 的各个字符依次是 `s[0], s[1], ..., s[strlen(s) - 1]` ， `s[strlen(s)]` 为结束标记 `"\0"` 。
9. 使用 `strcpy(a, b)` 、`strcmp(a, b)` 、`strcat(a, b)` 来执行字符串 `a` 和 `b` 之间的 “赋值” 、“比较” 和 “连接” 操作。上述函数全部在 `string.h` 中声明。

10. 解决 `scanf("%s", s)` 遇到空格会停下来的方法：

    1. `fgetc(fin)` ，读取一个打开的文件 `fin` ，读取一个字符，然后返回一个 `int` 值。如果文件结束， `fgetc` 会返回特殊标记 `EOF` 。一般情况下应当检查其这个 `int` 值不是 `EOF` 后再将其转换成 `char` 值。**如果从标准输入读取一个字符，可以使用 `getchar` ，等价于 `fgetc(stdin)` 。**

    2. `fgets(buf, maxn, fin)` 读取完整的一行，并放在字符数组 `buf` 中。其中 `buf` 的声明为 `char buf[maxn]` 。这个函数读取不超过 `maxn-1` 个字符，然后在末尾添上结束符 `"\0"` ，因此不会出现越界的情况。`buf` 总是以 `"\n"` 结尾，除非在文件结束前没遇到 `"\n"` 。标准输入版本为 `gets` （存在缓冲区溢出漏洞，C11标准中该函数被正式删除）。

       应当注意，不同 OS 的回车换行符是不一样的。

    |  系统   | 回车换行符 |      读取Windows文件的字符情况       |
    | :-----: | :--------: | :----------------------------------: |
    | Windows |  "\r""\n"  | fgetc和getchar会把"\r"吃掉，留下"\n" |
    |  Linux  |    "\n"    |  fgetc和getchar会先读"\r"，再读"\n"  |
    |  MacOS  |    "\r"    |         ~~不知道，书上没说~~         |

11. 头文件 `ctype.h` 中定义的 `isalpha` 、 `isdigit` 、`isprint` 用来判断字符的属性。`toupper` 、`tolower` 用来转换大小写。

