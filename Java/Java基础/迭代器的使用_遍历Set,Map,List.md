# 使用迭代器遍历容器

## 1、遍历List

```java
//遍历List容器的方法
    public static void testIteratorlist(){
        List<String> list = new ArrayList<>();
        list.add("aa");
        list.add("bb");
        list.add("cc");

        for(Iterator<String> iter = list.iterator();iter.hasNext();){
            String temp = iter.next();//返回当前内容，并指向下一个
            System.out.println(temp);
        }
    }
```

## 2、遍历Set

```java
//遍历Set容器的方法
    public static void testIteratorSet(){
        Set<String> set = new HashSet<>();
        set.add("a");
        set.add("b");
        set.add("c");

        for(Iterator<String> iter = set.iterator();iter.hasNext();){
            String temp = iter.next();
            System.out.println(temp);
        }
    }
```

## 3、遍历Map

```java
//遍历Map键值对的方法
    public static void testIteratorMap(){
        Map<Integer,String> map = new HashMap<>();
        map.put(100,"大哥");
        map.put(200,"二哥");
        map.put(20,"小哥");

        //得到安全的数组
//        Set<Map.Entry<Integer,String>> s1 = map.entrySet();
//
//        for(Iterator<Map.Entry<Integer,String>> iter = s1.iterator();iter.hasNext();){
//            Map.Entry<Integer,String> temp = iter.next();
//            System.out.println(temp.getKey() + "----" + temp.getValue());
//        }

        //另一种遍历Map容器的方法
        Set<Integer> s2 = map.keySet();
        for(Iterator<Integer> iter = s2.iterator();iter.hasNext();){
            Integer key = iter.next();
            System.out.println(key + "----" + map.get(key));
        }
    }
```

main方法

```java
public static void main(String[] args){
        //testIteratorlist();
        //testIteratorSet();
        testIteratorMap();
    }
```