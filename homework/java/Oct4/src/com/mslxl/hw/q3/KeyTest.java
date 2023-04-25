package com.mslxl.hw.q3;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class KeyTest extends JFrame{
    MyPanel mp = null;
    public KeyTest(){
        mp = new MyPanel();
        add(mp);
        addKeyListener(new KeyAdapter() {
            public void keyTyped(KeyEvent e) {}
            public void keyReleased(KeyEvent e) {}
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode()==KeyEvent.VK_UP)
                    mp.y -= 10;
                else if(e.getKeyCode()==KeyEvent.VK_DOWN)
                    mp.y += 10;
                else if(e.getKeyCode()==KeyEvent.VK_LEFT)
                    mp.x -= 10;
                else if(e.getKeyCode()==KeyEvent.VK_RIGHT)
                    mp.x += 10;
                mp.repaint();
            }
        });
        setSize(400,300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }
    public static void main(String[] args) {
        new KeyTest();
    }
}
class MyPanel extends JPanel {
    int x = 30;
    int y = 30;
    public void paint(Graphics g){
        super.paint(g);
        g.fillOval(x,y,12,12);
    }

}
