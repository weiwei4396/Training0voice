# Training0voice
Some training improves Linux C/C++

##### T1：从ifconfig的结果中提取出"eno4"的IP地址？
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
  
</details>







