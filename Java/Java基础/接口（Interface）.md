# 接口（interface）

## 为什么需要接口？接口和抽象类的区别？

+ 接口就是比“抽象类”还“抽象”的“抽象类”。可以更加规范的对子类进行约束。全面地专业地实现了：规范和具体实现的分离。

+ 接口就是规范

+ 子类通过 implements 来实现对接口中的规范

+ 接口不能创建实例，但是可以用于声明引用变量类型。

+ 一个类实现了接口，必须实现这个接口中的所有的方法，并且这些方法只能是Public的

+ **接口支持多继承**