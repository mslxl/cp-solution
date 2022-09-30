package q2;

import javax.swing.*;
public class Main extends JFrame {
    JTabbedPane tabPane = new JTabbedPane();

    public Main(){
        for (int i = 0; i < 3; i++) {
            tabPane.addTab("选项卡 " + (char)('A' + i), new JLabel("我是选项卡 " + (char)('A' + i)));
        }
        tabPane.setSelectedIndex(2);
        tabPane.addChangeListener(e -> System.out.println("我是选项卡 " + (char)('A' + tabPane.getSelectedIndex())));
        this.add(tabPane);
    }
    public static void main(String[] args) {
        JFrame main = new Main();
        main.setSize(300,400);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        main.setVisible(true);
    }
}
