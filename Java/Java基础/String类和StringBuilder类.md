### String类被称为不可变对象，我们打开String类的源码，如图：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-d1c44a0797beb43f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

                        String类部分源码

我们发现字符串内容全部储存到了value[]数组之中，而变量 value是 final类型的，也就是常量（只能被复制一次），这就是"不可变对象"的典型定义方式

---

在遇到字符串之间的拼接的时候，编译器会做出优化，即在编译阶段就会完成字符串的拼接，在使用 == 进行String对象之间的比较时，我们需要特别注意：

### 字符串常量拼接时的优化：

```java
public class TestString {
    public static void main(String[] args){
        String str1 = "Hello" + "Java";//相当于str1 = "HelloJava"；
        String str2 = "HelloJava";
        System.out.println(str1 == str2);//true

        String str3 = "Hello";
        String str4 = "Java";
        String str5 = str3 + str4;//编译的时候不知道变量中储存的是什么，所以没办法在编译的时候优化
        System.out.println(str5 == str2);//false
        System.out.println(str5.equals(str2));//true   equals()方法比较的就是值（大小）是不是相等
        //所以做字符串比较的时候，不要用" == "，用equals()方法
    }
}
```

---

### StringBuilder类便可修改字符串的值

可变字符序列的常用方法

```java
public class TestStringBuilder {
    public static void main(String[] args){
        //StringBuilder线程不安全，效率高（一般使用它）；StringBuffer线程安全，效率低
        StringBuilder sb = new StringBuilder("abcdefghijklmn");

        System.out.println(Integer.toHexString(sb.hashCode()));//输出字符串对象的地址
        System.out.println(sb);

        sb.setCharAt(2,'M');//替换
        System.out.println(Integer.toHexString(sb.hashCode()));
        System.out.println(sb);

        sb.reverse();//倒序
        System.out.println(sb);

        sb.append("我我我我哦我");//append()在后面添加
        System.out.println(sb);
    }
}
```

## 有字符串循环拼接时尽量选择StringBuilder

下面是String 和 StringBuilder的比较

```java
        //使用String拼接
        String str1 = " ";
        long num1 = Runtime.getRuntime().freeMemory();//获得系统剩余内存空间
        long time1 = System.currentTimeMillis();//获得系统当前时间
        for(int i = 0;i < 5000;i++){
            str1 = str1 + i;//相当于产生了10000个对象
        }
        long num2 = Runtime.getRuntime().freeMemory();
        long time2 = System.currentTimeMillis();
        System.out.println("String占用内存：" + (num1 - num2));
        System.out.println("String占用时间：" + (time2 - time1));
        //使用StringBuilder进行字符串的拼接
        StringBuilder sb2 = new StringBuilder(" ");
        long num3 = Runtime.getRuntime().freeMemory();//获得系统剩余内存空间
        long time3 = System.currentTimeMillis();//获得系统当前时间
        for(int i = 0;i < 5000;i++){
            sb2.append(i);
        }
        long num4 = Runtime.getRuntime().freeMemory();
        long time4 = System.currentTimeMillis();
        System.out.println("StringBuilder占用内存：" + (num3 - num4));
        System.out.println("StringBuilder占用时间：" + (time4 - time3));
```

结果：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-6492663ed3bfab9a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)