package com.test;
import java.util.*;
import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

/**
 * 异常
 */
class myException extends Exception {
    myException(String s){
        super(s);
    }
}

class testException{
    private static final int x = 5;

    public void show() throws myException{
        int i = 0;
        try {
            Scanner scan = new Scanner(System.in);
            i = scan.nextInt();
        }catch (Exception e){
            System.out.println(e.toString());
        }finally {
            System.out.println("***");
        }

        if (i < 0){
            throw new IllegalStateException("XXXX");
        }
        if (i == 1){
            throw new myException("sadasd");
        }
    }
}

/**
 * 异常
 */
class ThreadDemo extends Thread {
    private Thread t;
    private String threadName;

    ThreadDemo( String name) {
        threadName = name;
        System.out.println("Creating " +  threadName );
    }

    public void run() {
        System.out.println("Running " +  threadName );
        try {
            for(int i = 4; i > 0; i--) {
                System.out.println("Thread: " + threadName + ", " + i);
                // 让线程睡眠一会
                Thread.sleep(50);

            }
        }catch (InterruptedException e) {
            System.out.println("Thread " +  threadName + " interrupted.");
        }
        System.out.println("Thread " +  threadName + " exiting.");
    }

    public void start () {
        System.out.println("Starting " +  threadName );
        if (t == null) {
            t = new Thread (this, threadName);
            t.start ();
        }
    }
}

public class TestFrame extends JFrame implements Runnable {
    int i = 0;

    public TestFrame() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton b = new JButton();
        JLabel l = new JLabel();
        JTextField t = new JTextField();
        JFrame f = new JFrame();
        this.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                startThread();
            }
        });
    }

    private void startThread() {
        Thread t1 = new Thread(this);
        t1.start();
    }

    public void run() {
        for (i = 1; ; i = (i + 1) % 10) {
            try {
                repaint();
                Thread.sleep(500);
            } catch (InterruptedException e) {
                JOptionPane.showMessageDialog(null, e.getMessage(), "Exceptions", JOptionPane.WARNING_MESSAGE);
            }
        }
    }

    public void paint(Graphics g) {
        super.paint(g);
        int[] x1 = {80 + i * 10, 100 + i * 10, 50 + i * 10};
        int[] y1 = {50 + i * 10, 100 + i * 10, 80 + i * 10};
        int x = 80 + i * 10;
        int y = 50 + i * 10;
        if (i != 0) {
            g.setColor(Color.red);
            g.drawPolygon(x1, y1, 3);
            g.fillOval(x,y,60,60);
            g.drawOval(x,y,60,60);
            g.drawRect(x,y,60,60);
            g.fillRect(x,y,60,80);
            g.drawLine(x,y,2,5);
//            g.fillOval(50 + i * 10, 50 + i * 10, 100, 100);
        }
    }

    public static void main(String[] args) {


        TestFrame testFrame1 = new TestFrame();
        testFrame1.setBounds(100, 200, 300, 300);
        testFrame1.setTitle("Thread1");
        testFrame1.setVisible(true);
//        testFrame1.setLayout(new FlowLayout());
//        testFrame1.setLayout(new GridLayout(3,2));
//        testFrame1.setLayout(new BorderLayout());
//        testFrame1.setLayout(new CardLayout());
        /*
        //设置窗体标题
        frame.setTitle("Title");
        //设置布局管理器为流布局
        frame.setLayout(new FlowLayout());
        //设置窗体在屏幕中的位置
        frame.setLocation(x,y);
        //设置窗体的大小
        frame.setSize(w,h);
        //设置窗体在屏幕中的位置、大小
        frame.setBounds(x,y,w,h)；
        //添加组件
f.add(component);
//position是东西南北中：
//"South","East","North","West","Center"
f.add(position,component);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton btn = new JButton("btn1");
        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                repaint();
            }
        });
        * */

        TestFrame testFrame2 = new TestFrame();
        testFrame2.setBounds(400, 200, 300, 300);
        testFrame2.setTitle("Thread2");
        testFrame2.setVisible(true);

        TestFrame testFrame3 = new TestFrame();
        testFrame3.setBounds(700, 200, 300, 300);
        testFrame3.setTitle("Thread3");
        testFrame3.setVisible(true);
    }
}


/**
 *
 * */
class MyThreadPrinter2 implements Runnable {

    private String name;
    private Object prev;
    private Object self;

    private MyThreadPrinter2(String name, Object prev, Object self) {
        this.name = name;
        this.prev = prev;
        this.self = self;
    }

    @Override
    public void run() {
        int count = 10;
        while (count > 0) {
            synchronized (prev) {
                synchronized (self) {
                    System.out.print(name);
                    count--;

                    self.notify();
                }
                try {
                    prev.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        }
    }

    public static void main(String[] args) throws Exception {
        Object a = new Object();
        Object b = new Object();
        Object c = new Object();
        System.out.println(a.equals(b));
        MyThreadPrinter2 pa = new MyThreadPrinter2("A", c, a);
        MyThreadPrinter2 pb = new MyThreadPrinter2("B", a, b);
        MyThreadPrinter2 pc = new MyThreadPrinter2("C", b, c);


        new Thread(pa).start();
        Thread.sleep(100);  //确保按顺序A、B、C执行
        new Thread(pb).start();
        Thread.sleep(100);
        new Thread(pc).start();
        Thread.sleep(100);
    }
}


