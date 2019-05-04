package main;

import java.awt.*;
import java.awt.event.KeyEvent;

public class Plane extends GameObject {

    boolean left, right, up, down;
    boolean state = true;//飞机当前状态

    public void drawSelf(Graphics g) {//画出物体
        if(state){
            g.drawImage(getImg(),(int)getX(),(int)getY(),getWidth(),getHeight(),null);
            if(left){
                setX(getX() - getSpeed());
            }
            if(right){
                setX(getX() + getSpeed());
            }
            if(up){
                setY(getY() - getSpeed());
            }
            if(down){
                setY(getY() + getSpeed());
            }
        }else{

        }

    }

    public Plane(Image img, int x, int y) {
        setImg(img);
        setX(x);
        setY(y);
        //setWidth(getImg().getWidth(null));//获得图片的宽度和高度
        //setHeight(getImg().getHeight(null));
        setWidth(50);
        setHeight(50);
    }

    //按下某个键，增加相应的方向
    public void addDirection(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_LEFT:
                left = true;
                break;
            case KeyEvent.VK_UP:
                up = true;
                break;
            case KeyEvent.VK_RIGHT:
                right = true;
                break;
            case KeyEvent.VK_DOWN:
                down = true;
            default:
                break;
        }
    }
    //按下某个键，取消相应的方向
    public void minusDirection(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_LEFT:
                left = false;
                break;
            case KeyEvent.VK_UP:
                up = false;
                break;
            case KeyEvent.VK_RIGHT:
                right = false;
                break;
            case KeyEvent.VK_DOWN:
                down = false;
            default:
                break;
        }
    }
}
