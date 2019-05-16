
*泛型相当于给容器添加了一个标签*

泛型在集合中的应用

Collection接口

容器中的一些方法:

![image.png](https://upload-images.jianshu.io/upload_images/17431817-d498c6e8b154c916.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 1、Collection接口_List接口_ArrayList常用方法

```java
/** Collection接口_List接口_ArrayList常用方法 */
    public static void test01(){
        Collection<String> c = new ArrayList<>();//放字符串
        System.out.println(c.size());//0
        System.out.println(c.isEmpty());//true

        c.add("容器");
        c.add("测试容器");
        System.out.println(c);//[容器，测试容器]

        c.remove("测试容器");//移除"测试容器"，但是"测试容器"还在
        System.out.println(c);//[容器]

        c.clear();//清除了容器
        System.out.println(c.size());//0
    }
```

## 2、操作多个List_并集和交集

```java
/** 操作多个List_并集和交集 */
    public static void test02(){
        List<String> list01 = new ArrayList<>();
        list01.add("aa");
        list01.add("bb");
        list01.add("cc");

        List<String> list02 = new ArrayList<>();
        list02.add("dd");
        list02.add("ee");
        list02.add("ff");

        System.out.println("list01：" + list01);//[aa,bb,cc]
        System.out.println("list02：" + list02);//[dd,ee,ff]

        list01.addAll(list02);//[aa,bb,cc,dd,ee,ff]
        System.out.println(list01);

        list02.removeAll(list01);//[]
        System.out.println(list02);
    }
```

## 3、List是有序、可重复的容器。

1. 有序：List中每个元素都索引标记。可以根据元素的索引标记（在List中的位置）访问元素，从而精确控制这些元素。

2. 可重复：List允许加入重复的元素。更确切地讲，List通常允许满足 e1.equals(e2)的元素重复加入容器。


ArrayList底层使用数组实现的存储。特点：查询效率高，线程不安全。我们一般使用它。

List接口常用的实现类有三个：ArrayList、LinkedList和 Vector。

关于索引和顺序相关的方法：

```java
public static void test03(){
    List<String> lis = new ArrayList<>();

    list.add("A");
    list.add("B");
    list.add("C");
    list.add("D");
    System.out.println(list);//[A,B,C,D]

    list.add(2,"李四");//在下标为2的位置处插入"李四"
    System.out.println(list);//[A,B,李四,C,D]

    list.remove(2);//移除下标为 2的元素
    System.out.println(list);//[A,B,C,D]

    list.set(2,"张三");//把下标为 2的元素替换为 "张三"
    System.out.println(list);//[A,张三,C,D]

    System.out.println(list.get(2));//得到下标为 2的元素
    System.out.println(list.indexOf("B"));//返回元素"B"的下标，若元素"B"不存在，则返回-1
}
```

