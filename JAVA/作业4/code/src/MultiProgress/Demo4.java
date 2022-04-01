
package MultiProgress;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

/**
 * 画一个太极图
 *
 * @author Weirdo-world
 *
 */
public class Demo4 {
    public static void main(String[] args) {
        tj(800);
    }

    /**
     * @param w 定义图像的宽
     */
    public static void tj(int w) {
        BufferedImage bfi = new BufferedImage(w, w, BufferedImage.TYPE_INT_RGB);
        Graphics2D g = (Graphics2D) bfi.getGraphics();
        // 设置背景颜色
        g.setColor(new Color(211, 211, 211));
        g.fillRect(0, 0, w, w);
        // 左边半圆
        g.setColor(Color.WHITE);
        g.fillArc(0, 0, w, w, 90, 180);
        // 右边半圆
        g.setColor(Color.BLACK);
        g.fillArc(0, 0, w, w, -90, 180);
        // 上下部分调整
        g.setColor(Color.WHITE);
        g.fillOval(w / 4, 0, w / 2, w / 2);
        g.setColor(Color.BLACK);
        g.fillOval(w / 4, w / 2, w / 2, w / 2);
        g.fillOval(w * 3 / 8, w / 8, w / 4, w / 4);
        g.setColor(Color.WHITE);
        g.fillOval(w * 3 / 8, w * 5 / 8, w / 4, w / 4);
        // 设置字体
        Font font = new Font("STCAIYUN.TTF", Font.BOLD, w / 5);
        g.setFont(font);
        String t = "太";
        FontMetrics fm = g.getFontMetrics();
        int fw = fm.stringWidth(t);
        int fh = fm.getHeight();
        g.drawString(t, w / 2 - fw / 2, w / 4 - fh / 2 + font.getSize());
        g.setColor(Color.BLACK);
        String j = "极";
        g.drawString(j, w / 2 - fw / 2, w * 3 / 4 - fh / 2 + font.getSize());
        g.drawImage(bfi, w, w, null);
//        try {
//            ImageIO.write(bfi, "jpg", new File("g:/image/tmp/t.jpg"));
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
        g.dispose();
    }
}
