# 一、有无 static 的调用

```java
public class Test {

    //没有static 的变量
    int i = 10;

    //带有static的方法
    public static void doSome(){
        System.out.println("do some!");
    }

    //没有static的方法
    public void  doOther(){
        System.out.println("do other!");
    }

    public static void method1(){
        //调用doSome()
        //完整方式调用
        Test.doSome();
        //省略方式调用
        doSome();

        //调用doOther()
        //完整方式调用
        Test t = new Test();
        t.doOther();
        //省略方式调用
        System.out.println("No omission!");
        //访问i
        //完整方式调用
        System.out.println(t.i);
        //省略方式调用
        System.out.println("No omission");
    }

    //没有static的方法
    public void method2(){
        //调用doSome()
        //完整方式调用
        Test.doSome();
        //省略方式调用
        doSome();

        //调用doOther()
        //完整方式调用
        this.doOther();
        //省略方式调用
        doOther();

        //访问i
        //完整方式调用
        System.out.println("i = " + this.i);
        //省略方式调用
        System.out.println("i = " + i);

    }

    public static void main(String[] args){
        //要求在这里编写调用method1
        //使用完整方法调用
        Test.method1();
        //省略调用
        method1();
        //这里编写method2
        //完整方法调用
        Test t = new Test();
        t.method2();
        //省略方法调用
        System.out.println("No omission!");

    }

}

```

# 二、static 与 实例 的区别


     什么时候成员变量声明为实例变量呢？
          - 所有对象都有这个属性，并且所有对象的这个属性是不一样的
    
     什么时候成员变量声明为静态呢？
         - 所有对象都有这个属性，并且所有对象的这个属性是一样的的

     静态变量在类加载的时候初始化，内存在方法区开辟，访问的时候不需要创建对象，
     直接使用“类名.静态变量名”的方式访问
    

```java
public class Chinese {

    //身份证，每一个身份证都不同
    int id;

    String name;

    /**
     * 实例变量是一个Java对象就有一个一份，100个就有一百个Java对象，一百个country,
     * 【实例变量】储存在JVM堆内存当中，在构造方法执行的时候初始化
     *
     * 【静态变量】在类开始加载的时候初始化，对象还没创建，内存就开辟了
     *
     * 静态变量储存在方法区内存当中
     */
    //国籍都是中国
    static String country;

    public Chinese(){

    }
    public Chinese(int id,String name,String country){
        this.id = id;
        this.name = name;
        this.country = country;
    }

}

```