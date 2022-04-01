package MultiProgress;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class myFrame extends JFrame implements Runnable {
    int i = 0;
    Thread t;
    public myFrame() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                startT();
            }
        });
    }

    public void startT() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        for (i = 0; i < 20; i++) {
            try {
                repaint();
                Thread.sleep(200);
            } catch (Exception e) {
                System.out.println(e.toString());
            }
        }
    }

}