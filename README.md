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

(https://github.com/weiwei4396/Training0voice/blob/main/%E5%9B%BE%E7%89%87/zhuanhuan.jpg)

用到的c/c++基础：

1.[文件读取](https://blog.csdn.net/Hongwei_1990/article/details/94157375)
使用**fopen**函数来创建一个新的文件或者打开一个已有的文件, 这个调用会初始化类型**FILE**的一个对象, 类型**FILE**包含了所有用来控制流的必要的信息。下面是这个函数调用的原型：
```cpp
FILE * fopen( const char * filename , const char * mode );
```
**filename**是字符串, 用来命名文件, **mode**控制访问模式比如读写。

**fgetc**从文件读取单个字符的最简单的函数：
```cpp
int fgetc( FILE * fp );
```
**fgetc**函数从fp所指向的输入文件中读取一个字符。返回值是读取的字符, 如果发生错误则返回EOF。


2.**argc**是argument count的缩写, 表示传入main函数的参数个数; **argv**是argument vector的缩写, 表示传入main函数的参数序列或指针, 并且第一个参数argv[0]一定是程序的名称, 并且包含了程序所在的完整路径, 所以确切的说需要我们输入的main函数的参数个数应该是argc-1个;

```shell
g++ -std=c++11 wordCount.cpp -o Word
./Word your_text.txt
```


思考题2：统计txt文件中每个单词出现的数量。 依旧按照转换机的思路, 用每个单词作为哈希的key存储, 刚开始想用每个单词字符的加和作为key, 但是这样会引入哈希冲突。
```shell
g++ -std=c++11 eachwordCount.cpp -o Word
./Word your_text.txt
```



</details>
















