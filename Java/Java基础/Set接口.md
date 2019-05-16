# Set接口

**Set无序，不可重复**

**List有序，可重复**

> set接口继承自Collection，Set接口中没有新增方法，方法和Collection保持一致。我们在前面用过List学习的方法，在Set中仍然适用。因此，学习Set的使用将没有任何难度。

> Set容器特点：无序、不可重复。无序指Set中的元素没有索引，我们只能遍历查找；不可重复指不允许加入重复元素。更确切的讲，新元素如果和Set中某个元素通过equals()方法对比为true，则不能加入；甚至，Set中也只能放入一个null元素。

> Set常用的类有：HashSet、TreeSet、等，我们一般使用HashSet

## 手动实现HashSet

```java
import java.util.HashMap;
public class SxtHashSet {
    HashMap map;
    private static final Object PRESENT = new Object();

    public SxtHashSet(){
        map = new HashMap();
    }
    //容器长度
    public int size(){
        return map.size();
    }
    //添加元素
    public void add(Object obj){
        map.put(obj,PRESENT);
    }
    //重写toString方便打印
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for(Object key:map.keySet()){
            sb.append(key + ",");
        }
        sb.setCharAt(sb.length()-1,']');
        return sb.toString();
    }
    public static void main(String[] args) {
        SxtHashSet set = new SxtHashSet();
        set.add("aaa");
        set.add("bbb");
        set.add("ccc");
        System.out.println(set);
        System.out.println(set.size());
    }
}
```