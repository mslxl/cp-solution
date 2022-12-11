package quest1;
import java.awt.*;
import javax.swing.*;

class Canvas extends JPanel{
    Canvas(){};
    public void paint(Graphics g){
        super.paint(g);
        Graphics2D g_2d = (Graphics2D) g;
        Polygon polygon = new Polygon();
        polygon.addPoint(300,100);
        polygon.addPoint(150,500);
        polygon.addPoint(500,200);
        polygon.addPoint(100,200);
        polygon.addPoint(450,500);
        polygon.addPoint(300,100);
        g_2d.draw(polygon);
    }
}
public class Main{
    public static void main(String[] args) {
        JFrame windows1 = new JFrame("1");
        windows1.setVisible(true);
        windows1.setLocation(200,200);
        windows1.setSize(600,600);
        windows1.add(new Canvas());
    }
}
