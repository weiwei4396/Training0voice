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
这个问题的处理思路是转换机。


用到的c/c++基础：

文件读取：



</details>
















