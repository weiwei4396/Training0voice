# Training0voice
Some training improves Linux C/C++

#### Q1：从ifconfig的结果中提取出"eno4"的IP地址？
<details>
<summary> </summary>
这个问题的处理思路是通过关键字找到IP地址那一行(grep), 然后可以直接提取(awk)或者分别去掉IP地址前后的字符(sed);

思路一：
```shell
ifconfig eno4 | grep "inet " | awk '{print $2}'
```

思路二:
```shell
ifconfig eno4 | grep "inet " | sed "s/netmask.*$//g" | sed "s/^.*et //g"
```

sed这里的用法是 sed "s/要被取代的字符串/新的字符串/g"
</details>


#### Q2：统计一个txt文件中包含多少个单词？
<details>
<summary> </summary>
这个问题的处理思路是转换机。 一个文本文件中所有的字符可以包含为字母和分隔符。文件中的字符有两种状态，单词里和单词外，从单词外→单词里需要是字母，而从单词里→单词外需要是分隔符。

用到的c/c++基础：

1.文件读取[https://blog.csdn.net/Hongwei_1990/article/details/94157375]

2.**argc**是argument count的缩写, 表示传入main函数的参数个数; **argv**是argument vector的缩写, 表示传入main函数的参数序列或指针, 并且第一个参数argv[0]一定是程序的名称, 并且包含了程序所在的完整路径, 所以确切的说需要我们输入的main函数的参数个数应该是argc-1个;


</details>
















