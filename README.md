# SampleIme

一个基于微软开源代码的输入法

可以利用该输入法进行dll注入

1、在CSampleIME::ActivateEx里插入自定义操作，例如：

```C++
MessageBox(NULL, TEXT("ACTIVATE"), TEXT("INFO"), MB_OK);
```

2、编译

3、使用命令行安装输入法：

```C++
regsvr32 [path to]/SampleIME.dll
```

4、注入成功则每次切换到我们安装的输入法时出现弹窗
