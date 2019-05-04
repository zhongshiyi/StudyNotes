package main;

import java.awt.*;

/**
 * 爆炸类
 */
public class Explode {
    private double x,y;//爆炸图片的位置
    private int width,hight;//图片的大小

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHight() {
        return hight;
    }

    public void setHight(int hight) {
        this.hight = hight;
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

    static Image[] imgs = new Image[6];
    static {
        for(int i = 0;i < 6;i++){
            imgs[i] = GameUtil.getImage("images/explosion_" + (i+1) + ".png");
            imgs[i].getWidth(null);
        }
    }
    int count;//计数

    public void draw(Graphics g){
        if(count < 6){
            g.drawImage(imgs[count],(int)getX(),(int)getY(),getWidth(),getHight(),null);
            count++;
        }
    }

    public Explode(double x,double y){
        setX(x);
        setY(y);
        setWidth(80);
        setHight(80);
    }
}
