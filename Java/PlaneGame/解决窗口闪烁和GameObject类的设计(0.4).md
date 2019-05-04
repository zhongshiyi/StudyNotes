# 1、解决窗口闪烁

在MyGameFrame类中添加一句：private Image offScreenImage = null;

```java
public void update(Graphics g){//添加双缓冲技术，解决窗口闪烁的问题
        if(offScreenImage == null)
            offScreenImage = this.createImage(600,600);//这是游戏窗口的宽度和高度
        Graphics gOff = offScreenImage.getGraphics();
        paint(gOff);
        g.drawImage(offScreenImage,0,0,null);
    }
```


# 2、创建游戏物品的父类

GameObject.java

```java
package main;

import java.awt.*;

/**
 * 游戏物品的父类
 */
public class GameObject {
    private Image img;
    private double x,y;
    private int speed;
    private int width,height;

    public Image getImg() {
        return img;
    }

    public void setImg(Image img) {
        this.img = img;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    /**
     * 返回物体所在的矩形，便于后续的碰撞检测
     * @return
     */
    public Rectangle getRect(){
        return new Rectangle((int)getX(),(int)getY(),getWidth(),getHeight());
    }
}
```

## 并返回了物体所在的矩形，便于后续的碰撞检测