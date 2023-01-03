package q1;

import javax.swing.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

public class Main extends JFrame {
    JMenuBar bar = new JMenuBar();
    JMenu menu = new JMenu("菜单");
    JMenuItem item1 = new JMenuItem("菜单项1");
    JMenuItem item2 = new JMenuItem("菜单项2");
    JMenu subMenu = new JMenu("子菜单");
    JMenuItem subMenuItem1 = new JMenuItem("子菜单的菜单项");
    public Main(){
        item1.setAccelerator(KeyStroke.getKeyStroke("A"));
        item2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_B,InputEvent.CTRL_DOWN_MASK));

        bar.add(menu);
        menu.add(item1);
        menu.add(item2);
        menu.add(subMenu);
        subMenu.add(subMenuItem1);
        this.setSize(300,100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setJMenuBar(bar);
    }
    public static void main(String[] args) {
        new Main().setVisible(true);
    }
}
