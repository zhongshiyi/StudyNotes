# 一、集合中Map接口的使用方法

## Map接口

1. Map提供了一种映射关系，其中的元素是以键值对（key-value）的形式储存的，能够实现根据key快速查找value；

2. Map中的键值对以Entry类型的对象实例形式存在；

3. 键（key）不可重复。value值可以重复，一个value值可以和对个key形成对应关系，每个键最多只能对应一个value值；

4. Map支持泛型，形式如Map<K,V>

5. Map中使用 put(K key,V value)添加元素：存储


![Map.png](https://upload-images.jianshu.io/upload_images/17431817-f77baff41bff2a9c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## HashMap原理：

+ HashMap底层实现了哈希表，这是一种非常重要的数据结构

+ 哈希表就是"数组 + 链表"

![HashMap.png](https://upload-images.jianshu.io/upload_images/17431817-5cfc0c4d0b503805.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](https://upload-images.jianshu.io/upload_images/17431817-b855038ac6558b8e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 四种遍历Map的方法：

+ **1、使用entries来遍历**

```java
Map<Integer, Integer> map = new HashMap<Integer, Integer>();
 
for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
 
    System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
 
}
```
注意：for-each循环在Java 5中被引入所以该方法只能应用于java 5或更高的版本中。如果你遍历的是一个空的map对象，for-each循环将抛出NullPointerException，因此在遍历前你总是应该检查空引用。

+ **2、遍历key或value**

```java
Map<Integer, Integer> map = new HashMap<Integer, Integer>();
 
//遍历map中的键
for (Integer key : map.keySet()) {
    System.out.println("Key = " + key);
}
 
//遍历map中的值
for (Integer value : map.values()) {
    System.out.println("Value = " + value);
}
```

+ **3、使用Iterator来遍历**

```java
Map<Integer, Integer> map = new HashMap<Integer, Integer>();
Iterator<Map.Entry<Integer, Integer>> entries = map.entrySet().iterator();
while (entries.hasNext()) {
    Map.Entry<Integer, Integer> entry = entries.next();
    System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
}
```
该种方式看起来冗余却有其优点所在。首先，在老版本java中这是惟一遍历map的方式。另一个好处是，你可以在遍历时调用iterator.remove()来删除entries，另两个方法则不能。根据javadoc的说明，如果在for-each遍历中尝试使用此方法，结果是不可预测的。
       从性能方面看，该方法类同于for-each遍历（即方法二）的性能

+ **4、通过键找值遍历（效率低）**

```java
Map<Integer, Integer> map = new HashMap<Integer, Integer>();
for (Integer key : map.keySet()) {
    Integer value = map.get(key);
    System.out.println("Key = " + key + ", Value = " + value);
}
```

作为方法一的替代，这个代码看上去更加干净；但实际上它相当慢且无效率。因为从键取值是耗时的操作（与方法一相比，在不同的Map实现中该方法慢了20%~200%）。如果你安装了FindBugs，它会做出检查并警告你关于哪些是低效率的遍历。所以尽量避免使用。

# 二、手动实现一个简单的HashMap

#### 链表及节点内部的结构：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-11a2aae8d0d10061.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 1、实现基本结构：Node.java、TestHashMap.java

```java
public class Node {
    int hash;
    Object key;
    Object value;
    Node next;
}
```

```java
public class TestHashMap {

    Node[] table;//位桶数组。bucket array
    int size;   //存放键值对的个数

    public TestHashMap(){
        table = new Node[16];//长度一定要是2的整数倍
    }

    public void put(Object key,Object value){
        Node newNode = new Node();
        newNode.hash = myHash(key.hashCode(),table.length);
        newNode.key = key;
        newNode.value = value;
        newNode.next = null;

        Node temp = table[newNode.hash];
        if(temp == null){
            //如果数组为空，直接将节点放进去
            table[newNode.hash] = newNode;
        }else{
            //此处数组元素不为空，则遍历对应来链表

        }
    }
    /** 得到自己的hash值 */
    public int myHash(int v,int length){
        System.out.println("hash in myHash:" + (v&(length-1)));//直接位运算，效率高
        System.out.println("hash in myHash:" + (v%(length-1)));//取模运算，效率低
        return v&(length-1);
    }

    public static void main(String[] args){
        TestHashMap m = new TestHashMap();
        m.put(10,"大哥");
        m.put(13,"二哥");
        m.put(25,"三哥");
        m.size = 3;

        System.out.println(m);
    }
}
```
---

### 2、完成了put()方法，增加了如果key重复时，节点覆盖的操作

```java
/** 完成了put()方法，增加了如果key重复时，节点覆盖的操作 */
    public void put(Object key,Object value){
        Node newNode = new Node();
        newNode.hash = myHash(key.hashCode(),table.length);
        newNode.key = key;
        newNode.value = value;
        newNode.next = null;

        Node temp = table[newNode.hash];
        Node iterLast = null;//正在遍历的最后一个节点元素
        boolean keyRepeat = false;//检查是否重复
        if(temp == null){
            //如果数组为空，直接将节点放进去
            table[newNode.hash] = newNode;
        }else{
            //数组不为空，需要遍历链表
            while(temp != null){
                //判断key如果重复，则覆盖
                if(temp.key.equals(key)){
                    System.out.println("key重复了！");
                    temp.value = value;//覆盖value
                    keyRepeat = true;
                    break;
                }else {
                    //key不重复,则遍历下一个
                    iterLast = temp;
                    temp = temp.next;
                }
            }
            if(!keyRepeat){//不重复就添加到链表最后
                iterLast.next = newNode;//添加新节点
            }
        }
    }
    public static void main(String[] args){
        TestHashMap m = new TestHashMap();
        m.put(10,"大哥");
        m.put(21,"二哥");
        m.put(33,"三哥");
        m.put(21,"老妹儿");

        m.put(37,"哥");
        m.put(53,"哥哥");
        m.put(69,"哥哥哥");//在一条链表上
        System.out.println(m);
    }
```

连接相同hash值得节点：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-5d2b850df9b2ef9a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 3、重写toString方法，方便打印Map内容

```java
 /** 重写toString方法，方便打印Map内容 */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("{");

        for(int i = 0;i < table.length;i++){//遍历数组
            Node temp = table[i];
            while(temp != null){
                sb.append(temp.key + ":" + temp.value + ",");
                temp = temp.next;
            }
        }
        sb.setCharAt(sb.length()-1,'}');
        return sb.toString();
    }
```

![image.png](https://upload-images.jianshu.io/upload_images/17431817-5399a6dee331b92e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 4、增加get()方法，查找键值对

```java
//查找key，所对应得value值
    public Object get(Object key){
        int hash = myHash(key.hashCode(),table.length);
        Object value = null;
        if(table[hash] != null){
            Node temp = table[hash];
            while(temp != null){
                //相等，找到键值对，返回value
                if(temp.key.equals(key)){
                    value = temp.value;
                    break;
                }else{
                    temp = temp.next;
                }
            }
        }
        return value;
    }
```

在主函数中输入：

> System.out.println(m.get(21));

得到结果：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-3561108e1f402459.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 5、增加泛型（全部代码）

Node.java

```java
public class Node<K,V> {
    int hash;
    K key;
    V value;
    Node next;
}
```

TestHashMap.java

```java
public class TestHashMap<K,V> {
    Node[] table;//位桶数组
    int size;//存放键值对的个数
    public TestHashMap(){
        table = new Node[16];//必须是2的整数倍
    }

    public static int myHash(int hashCode,int length){
        return hashCode&(length-1);
    }
    /** 重写toString方法，方便打印Map内容 */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("{");

        for(int i = 0;i < table.length;i++){//遍历数组
            Node temp = table[i];
            while(temp != null){
                sb.append(temp.key + ":" + temp.value + ",");
                temp = temp.next;
            }
        }
        sb.setCharAt(sb.length()-1,'}');
        return sb.toString();
    }
    public void put(K key,V value){
        Node newNode = new Node();
        newNode.hash = myHash(key.hashCode(),table.length);
        newNode.key = key;
        newNode.value = value;
        newNode.next = null;

        Node temp = table[newNode.hash];
        Node iterLast = null;//正在遍历的最后一个节点元素
        boolean keyRepeat = false;//检查是否重复
        if(temp == null){
            //如果数组为空，直接将节点放进去
            table[newNode.hash] = newNode;
        }else{
            //数组不为空，需要遍历链表
            while(temp != null){
                //判断key如果重复，则覆盖
                if(temp.key.equals(key)){
                    //System.out.println("key重复了！");
                    temp.value = value;//覆盖value
                    keyRepeat = true;
                    break;
                }else {
                    //key不重复,则遍历下一个
                    iterLast = temp;
                    temp = temp.next;
                }
            }
            if(!keyRepeat){//不重复就添加到链表最后
                iterLast.next = newNode;//添加新节点
            }
        }
    }
    //查找key，所对应得value值
    public V get(K key){
        int hash = myHash(key.hashCode(),table.length);
        V value = null;
        if(table[hash] != null){
            Node temp = table[hash];
            while(temp != null){
                //相等，找到键值对，返回value
                if(temp.key.equals(key)){
                    value = (V)temp.value;
                    break;
                }else{
                    temp = temp.next;
                }
            }
        }
        return value;
    }

    public static void main(String[] args){
        TestHashMap<Integer,String> m = new TestHashMap<Integer, String>();
        m.put(10,"大哥");
        m.put(21,"二哥");
        m.put(33,"三哥");
        m.put(21,"老妹儿");
        
        m.put(37,"哥");
        m.put(53,"哥哥");
        m.put(69,"哥哥哥");//在一条链表上
        System.out.println(m);
        System.out.println(m.get(53));
        System.out.println(m.get(21));
    }
}
```