# File类的基本用法

### java.io.File类：**代表文件和目录。**，在开发中，读取文件，删除文件，生成文件，修改文件的属性时，经常会用到本类。以及 mkdir()和 mkdirs()方法的区别。

```java
public class TestFile {
    public static void main(String[] args) throws IOException {//抛出异常
        File f1 = new File("d:/a.txt");
        File f2 = new File("d:\\a.txt");//同样的意思
        System.out.println(f1);
        System.out.println(f2);
        //修改文件名为：bb.txt ,改名之后对象 f1、f2便不存在了
        f1.renameTo(new File("d:/bb.txt"));

        System.out.println(System.getProperty("user.dir"));//当前文件的目录

        //创建了一个gg.txt文件在 Test包下
        File newfile = new File("gg.txt");
        newfile.createNewFile();

        System.out.println("File 是否存在：" + newfile.exists());
        System.out.println("File 是否是根目录：" + newfile.isDirectory());
        System.out.println("File 是否是文件：" + newfile.isFile());
        System.out.println("File 最后修改时间：" + new Date(newfile.lastModified()));
        System.out.println("File 的大小：" + newfile.length());
        System.out.println("File 的文件名：" + newfile.getName());
        System.out.println("File 的目录路径：" + newfile.getAbsolutePath());

        /** mkdir()和 mkdirs()的区别*/
        File f3 = new File("d:\\电影\\华语\\大陆");
        boolean flag1 = f3.mkdir();//表示创建的是"华语"文件夹，但是如果目录结构中有一个文件不存在，就不能创建
        //例如：现在没有"电影"、"华语"的文件夹，就不能创建"大陆"的文件夹
        System.out.println(flag1);//false
        File f4 = new File("d:\\电影\\华语\\大陆");//不存在目录结构也没关系，创建整个目录树
        boolean flag2 = f4.mkdirs();
        System.out.println(flag2);//true
    }
}
```

## 使用递归算法遍历目录结构，以树状结构展示目录树：

```java
public class TestFile {
    public static void main(String[] args) throws IOException {//抛出异常
        File f = new File("D:\\GithubRepositories\\StudyNotes\\Java");
        printFile(f,0);
    }

    static void printFile(File file,int level){
        /**输出层数*/
        for(int i = 0;i < level;i++){//每一个文件名前面都有"-"，若是更下一个则文件名字前面的"-"的数目加一
            System.out.print("-");
        }

        System.out.println(file.getName());//打印文件名字
        if(file.isDirectory()){//判断是不是根目录
            File[] files = file.listFiles();
            for(File temp:files){
                printFile(temp,level+1);
            }
        }
    }
}
```

#### 结果：

![snip_2.png](https://upload-images.jianshu.io/upload_images/17431817-f6afd289a7b44151.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
