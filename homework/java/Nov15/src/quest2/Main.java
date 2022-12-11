package quest2;

import java.awt.geom.*;
import java.awt.*;
import javax.swing.*;

class Canvas extends JPanel {
    Canvas() {
    }


    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g_2d = (Graphics2D) g;
        QuadCurve2D quadCurve2D = new QuadCurve2D.Double(100, 100, 400, 700, 700, 100);
        g_2d.draw(quadCurve2D);

        AffineTransform trans = new AffineTransform();
        trans.rotate(30.0 * 3.1415926 / 180, 100, 400);
        g_2d.setTransform(trans);
        g_2d.draw(quadCurve2D);
    }
}

public class Main {
    public static void main(String[] args) {
        JFrame windows1 = new JFrame("2");
        windows1.setVisible(true);
        windows1.setLocation(100, 100);
        windows1.setSize(800, 500);
        windows1.add(new Canvas());
    }
}