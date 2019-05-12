目的：复习容器，增加熟练度，练手，体会底层原理

## 1、最简单方式_增加泛型

```java
public class SxtArrayList<E> {
    private Object[] elementData;//定义了一个Object数组
    private int size;//长度

    private static final int DEFAULT_CAPACITY = 20;//默认容量

    public SxtArrayList(){//默认构造方法
        elementData = new Object[DEFAULT_CAPACITY];
    }
    public SxtArrayList(int capacity){//构造方法，输入大小
        elementData = new Object[capacity];
    }

    public void add(E element){
        elementData[size++] = element;
    }
    //重写 toString方法
    //打印容器类的元素
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for(int i = 0;i < size;i++){
            sb.append(elementData[i] + ",");
        }
        sb.setCharAt(sb.length() - 1,']');//将最后的','替换为']'
        return sb.toString();
    }

    public static void main(String[] args){
        SxtArrayList s1 = new SxtArrayList(20);
        s1.add(2);
        s1.add(4);
        System.out.println(s1);//[2,4]
    }
}
```

## 2、数组扩容功能

修改了add()方法，和主方法

```java
public void add(E element){

    if(size == elementData.length){//扩大数组为原数组的1.5倍
        //右移一位相当于除以二
        Object newArray = new Object[elementData.length + (elementData.length >> 1)];
         //拷贝到新数组
        System.arraycopy(elementData,0,newArray,0,elementData.length);

           elementData = (Object[]) newArray;
    }
    elementData[size++] = element;
}
```

```java
public static void main(String[] args){
        SxtArrayList s1 = new SxtArrayList();
        s1.add(2);
        s1.add(4);
        System.out.println(s1);//[2,4]
        /** 这里容量扩容了 */
        for(int i = 0;i < 40;i++)
            s1.add("zhong" + i);
        System.out.println(s1);
}
```

实现了数组的扩容：

![image.png](https://upload-images.jianshu.io/upload_images/17431817-92cbe0380afb5e61.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 3、索引越界功能

增加了get()、set()方法以及索引异常判断

```java
/** 编写 get() set() 方法 */
    public E get(int index){

        return (E)elementData[index];
    }
    public void set(int index,E element){
        //索引合法判断
        checkRange(index);
        elementData[index] = element;
    }

    public void checkRange(int index){
        //索引合法判断
        if(index < 0 || index >= size){
            //不合法,手动抛出异常
            throw new RuntimeException("索引不合法！");
        }
    }
```

并修改了构造方法SxArrayList(int capacity)，使逻辑更加严密

```java
public SxtArrayList(int capacity){//构造方法，输入大小
        if(capacity < 0){
            throw new RuntimeException("容量不能为负数！");
        }else{
            elementData = new Object[capacity];
        }
    }
```

## 4、增加remove(),isEmpty()等方法

remove()方法

```java
/** 编写移除方法 */
    public void remove(E element){
        int i = 0;
        while(i < size){
            if(element.equals(get(i))){//容器中所有的比较操作都是equals，而不是 ==
                remove(i);
            }
            i++;
        }
    }
    public void remove(int index){
        checkRange(index);//检查检查
        System.arraycopy(elementData,index+1,elementData,index,elementData.length-index-1);
        elementData[--size] = null;
    }
```

isEmpty()方法

```java
public boolean isEmpty(){
        return size == 0 ? true:false;
    }
```

# 完整代码：

```java
package practice;

public class SxtArrayList<E> {
    private Object[] elementData;//定义了一个Object数组
    private int size;//长度

    private static final int DEFAULT_CAPACITY = 20;//默认容量

    public SxtArrayList(){//默认构造方法
        elementData = new Object[DEFAULT_CAPACITY];
    }
    public SxtArrayList(int capacity){//构造方法，输入大小
        if(capacity < 0){
            throw new RuntimeException("容量不能为负数！");
        }else{
            elementData = new Object[capacity];
        }
    }

    public void add(E element){

        if(size == elementData.length){//扩大数组为原数组的1.5倍
            //右移一位相当于除以二
            Object newArray = new Object[elementData.length + (elementData.length >> 1)];
            //拷贝到新数组
            System.arraycopy(elementData,0,newArray,0,elementData.length);

            elementData = (Object[]) newArray;
        }
        elementData[size++] = element;
    }
    /** 编写移除方法 */
    public void remove(E element){
        int i = 0;
        while(i < size){
            if(element.equals(get(i))){//容器中所有的比较操作都是equals，而不是 ==
                remove(i);
            }
            i++;
        }
    }
    public void remove(int index){
        checkRange(index);//检查检查
        System.arraycopy(elementData,index+1,elementData,index,elementData.length-index-1);
        elementData[--size] = null;
    }

    /** 编写 get() set() 方法 */
    public E get(int index){

        return (E)elementData[index];
    }
    public void set(int index,E element){
        //索引合法判断
        checkRange(index);
        elementData[index] = element;
    }

    public void checkRange(int index){
        //索引合法判断
        if(index < 0 || index >= size){
            //不合法,手动抛出异常
            throw new RuntimeException("索引不合法！");
        }
    }

    public boolean isEmpty(){
        return size == 0 ? true:false;
    }

    //重写 toString方法
    //打印容器类的元素
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(20);
        sb.append("[");
        for(int i = 0;i < size;i++){
            sb.append(elementData[i] + ",");
        }
        sb.setCharAt(sb.length() - 1,']');//将最后的','替换为']'
        return sb.toString();
    }

    public static void main(String[] args){
        SxtArrayList s1 = new SxtArrayList();
        s1.add(2);
        s1.add(4);
        System.out.println(s1);//[2,4]
        /** 这里容量扩容了 */
        for(int i = 0;i < 40;i++)
            s1.add("zhong" + i);
        System.out.println(s1);
        System.out.println(s1.get(20));//zhong18
        s1.set(20,"change");
        System.out.println(s1.get(20));//change

        SxtArrayList s2 = new SxtArrayList();
        s2.add("A");
        s2.add("B");
        s2.add("C");
        s2.remove("B");
        System.out.println(s2);
        System.out.println(s2.isEmpty());
    }
}
```