package com.mslxl.hw.q2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MainWindowMethod2 implements MouseListener {
    JFrame jf;
    JLabel jl;
    public MainWindowMethod2(){
        jf = new JFrame();
        jl = new JLabel(new ImageIcon("src\\chapter9\\school.jpg"));
        jf.add(jl,BorderLayout.CENTER);
        jf.setTitle("学生管理系统");
        jf.setSize(800,600);
        Dimension size = Toolkit.getDefaultToolkit().getScreenSize();
        jf.setLocation((size.width-jf.getWidth())/2,(size.height-jf.getHeight())/2);
        jf.addMouseListener(this );
        jf.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jf.setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        jf.setTitle(String.format("x:%d, y:%d", e.getX(), e.getY()));

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    public static void main(String[] args) {
        new MainWindowMethod2();
    }
}
