## 注意：Collection是接口，Collections是工具类

```java
public class TestCollections {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        for(int i = 0;i < 10;i++){
            list.add("zhong：" + i);
        }
        System.out.println(list);

        Collections.shuffle(list);//洗牌，将list容器里的元素随机排列
        System.out.println(list);

        Collections.sort(list);//按照递增的方式排列，若自定义的类，则使用：Comparable接口
        System.out.println(list);

        System.out.println(Collections.binarySearch(list,"zhong：4"));//二分法查找

        Collections.reverse(list);//逆序排列
        System.out.println(list);


    }
}
```

![image.png](https://upload-images.jianshu.io/upload_images/17431817-ada657a4ef4ca09d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
