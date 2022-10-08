package com.mslxl.hw.q2;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.*;
public class MainWindowMethod1 extends MouseAdapter {
    JFrame jf;
    JLabel jl;
    public MainWindowMethod1(){
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
    public static void main(String[] args) {
        new MainWindowMethod1();
    }
}
