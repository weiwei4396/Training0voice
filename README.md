# Training0voice
Some training improves Linux C/C++

##### T1：从ifconfig的结果中提取出"eno4"的IP地址？
<details>
<summary> </summary>

``shell
ifconfig eno4 | grep "inet " | awk '{print $2}'
``


``shell
ifconfig eno4 | grep "inet " | sed "s/netmask.*$//g" | sed "s/^.*et //g"
``
  
</details>







