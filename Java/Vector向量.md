# Vector向量

Vector底层是用数组实现的 List，相关的方法都加了同步检查，因此"线程安全，效率低"。比如，indexOf()方法就增加了synchronized同步标记。

![image.png](https://upload-images.jianshu.io/upload_images/17431817-2552fbd999b75d7a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

<center>Vector底层源码</center>

如何使用ArrayList、LinkedList、Vector？

+ 1.需要线程安全时，使用Vector

+ 2.不存在线程安全问题时，并且查找加多用ArrayList（一般情况都是用它）

+ 3.不存在线程安全问题时，增加或删除元素较多用LinkedList。