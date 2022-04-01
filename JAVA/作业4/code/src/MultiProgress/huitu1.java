package MultiProgress;

import java.awt.*;

public class huitu1 extends myFrame {

    public void paint(Graphics g) {
        super.paint(g);
        if (i != 0)
            g.setColor(Color.RED);
//        g.drawOval(50 + i * 10, 50 + i * 10, 30, 30);
//        super.paint(g);
//        g.drawOval(50, 10, 30, 30);
//        g.drawRect(100, 100, 60, 60);
        g.drawString("love",50 + i * 10,50 + i * 10);
    }
}
