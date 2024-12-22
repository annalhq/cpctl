## Fast read template

Author: [CYJian](https://www.luogu.com.cn/user/20782)
Source: https://www.luogu.com.cn/paste/i11c3ppx

用法：

使用 gi(x); 读入一个任意的整型 x 等价于 scanf("%d", &x);其中可以将 %d 自动识别为对应类型。

使用 print(x); 输出一个任意的整型 x 等价于 printf("%d", x);其中可以将 %d 自动识别为对应类型。

使用 gc(c); 读入一个字符 c 等价于 scanf("%c", &c)

使用 pc(c); 输出一个字符 c 等价于 putchar(c);

使用 gstr(str); 读入一个字符串 str 等价于 scanf("%s", str); 可以用 gstr(str + 1); 替换 scanf("%s", str + 1);

使用 pstr(str); 输出一个字符串 str 等价于 printf("%s", str);