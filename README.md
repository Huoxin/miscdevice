miscdevice----
==============
1.misc_dev.c是驱动程序
2.Makefile用于编译
3.usr_app.c用户态程序


misc_register就是用主标号10调用register_chrdev()的。

misc设备其实也就是特殊的字符设备，可自动生成设备节点。
