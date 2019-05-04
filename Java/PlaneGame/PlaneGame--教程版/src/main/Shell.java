package main;

import java.awt.*;

public class Shell extends GameObject {

    private double degree;

    public double getDegree() {
        return degree;
    }

    public void setDegree(double degree) {
        this.degree = degree;
    }

    public Shell(Image img){
        setImg(img);
        setX(200);
        setY(200);
        setWidth(10);
        setHeight(10);
        setSpeed(5);
        setDegree(Math.random()*Math.PI*2);
    }
    public void drawSelf(Graphics g){
        g.drawImage(getImg(),(int)getX(),(int)getY(),getWidth(),getHeight(),null);
        //炮弹沿着任意角度去飞
        setX(getX() + getSpeed()*Math.cos(degree));
        setY(getY() + getSpeed()*Math.sin(degree));

        //使炮弹在界面边缘反弹
        if(getX() < 10 || getX() > Constant.GAME_WIDTH - 20){//左右
            setDegree(Math.PI - getDegree());
        }
        if(getY() < 35 || getY() > Constant.GAME_HEIGHT - 20){//上下
            setDegree(- getDegree());
        }
    }
}
