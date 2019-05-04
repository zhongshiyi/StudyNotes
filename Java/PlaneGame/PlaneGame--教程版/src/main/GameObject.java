package main;

import java.awt.*;

/**
 * 游戏物品的父类
 */
public class GameObject {
    private Image img;
    private double x,y;
    private int speed = Constant.PLANE_SPEED;
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
