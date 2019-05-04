package main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Date;

/**
 * 飞机游戏的主窗口
 */
public class MyGameFrame extends Frame {
    private Image offScreenImage = null;

    Image planeImage = GameUtil.getImage("images/plane.png");//调用图片
    Image background = GameUtil.getImage("images/background.jpg");
    Image shellImage = GameUtil.getImage("images/shell.png");

    Plane plane = new Plane(planeImage,450,550);//飞机的初始位置
    Shell[] shells = new Shell[Constant.SHELL_NUMBER];//生成炮弹数组，数目50

    Explode explode;//声明爆炸对象
    Date startTime = new Date();//起始时间
    Date endTime;
    long period;//时间

    @Override
    public void paint(Graphics g) { //自动被调用，g 相当于一支画笔
        //super.paint(g);
        g.drawImage(background,0,0,null);//在界面上展示出来
        plane.drawSelf(g);//画飞机
        //画出所有的炮弹
        for(int i = 0;i < shells.length;i++) {
            shells[i].drawSelf(g);

            boolean crash = shells[i].getRect().intersects(plane.getRect());

            if (crash) {
                //System.out.println("相撞了！");
                plane.state = false;
                if (explode == null) {
                    explode = new Explode(plane.getX(), plane.getY());

                    endTime = new Date();
                    period = (endTime.getTime() - startTime.getTime()) / 1000;//得到游戏持续的时间
                }
                explode.draw(g);
            }
            //计时功能，给出提示
            if (!plane.state) {
                g.setColor(Color.WHITE);
                Font f = new Font("宋体", Font.BOLD, 50);
                g.setFont(f);
                g.drawString("时间：" + period + "秒", 200, 100);
            }
        }
    }
    //内部类
    //帮助我们反复的重画窗口
    class PaintThread extends Thread{
        @Override
        public void run() {
            super.run();
            while(true){
                //System.out.println("重画窗口一次！");
                repaint();  //重画
                try{
                    Thread.sleep(40);   //1s = 1000ms
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        }
    }
    //键盘监听内部类
    class KeyMonitor extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
            //System.out.println("按下：" + e.getKeyCode());
            plane.addDirection(e);
        }

        @Override
        public void keyReleased(KeyEvent e) {
            //System.out.println("松开：" + e.getKeyCode());
            plane.minusDirection(e);
        }
    }

    /**
     * 初始化窗口
     */
    public void launchFrame(){
        this.setTitle("Miles 制作");
        this.setVisible(true);
        this.setSize(Constant.GAME_WIDTH,Constant.GAME_HEIGHT);
        this.setLocation(Constant.GAME_LOCATION_X,Constant.GAME_LOCATION_Y);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);     //点推出结束程序
            }
        });

        new PaintThread().start(); //启动重画窗口的线程
        addKeyListener(new KeyMonitor());//给窗口增加了键盘的监听

        //初始化50个炮弹
        for(int i = 0;i < shells.length;i++){
            shells[i] = new Shell(shellImage);
        }
    }
    //入口
    public static void main(String[] args){
        MyGameFrame f = new MyGameFrame();
        f.launchFrame();
    }

    public void update(Graphics g){//添加双缓冲技术，解决窗口闪烁的问题
        if(offScreenImage == null)
            offScreenImage = this.createImage(Constant.GAME_WIDTH,Constant.GAME_HEIGHT);//这是游戏窗口的宽度和高度
        Graphics gOff = offScreenImage.getGraphics();
        paint(gOff);
        g.drawImage(offScreenImage,0,0,null);
    }
}
