package q3;

import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    JPanel leftPanel = new JPanel();
    JLabel image = new JLabel();
    JScrollPane scrollPane = new JScrollPane(image);
    JSplitPane splitPane = new JSplitPane();
    JButton btnShowScroll = new JButton("显示滚动条");
    JButton btnHideScroll = new JButton("隐藏滚动条");
    JButton btnExit = new JButton("退出");
    public Main(){
        leftPanel.setLayout(new GridLayout(3,0));
        leftPanel.add(btnShowScroll);
        leftPanel.add(btnHideScroll);
        leftPanel.add(btnExit);

        splitPane.setLeftComponent(leftPanel);
        splitPane.setRightComponent(scrollPane);

        ImageIcon icon = new ImageIcon(Main.class.getResource("/q3/bg.jpg"));
        image.setIcon(icon);

        btnShowScroll.addActionListener(e -> updateScrollbar(true));
        btnHideScroll.addActionListener(e -> updateScrollbar(false));
        btnExit.addActionListener(e -> System.exit(0));
        updateScrollbar(true);
        this.setContentPane(splitPane);
    }

    private void updateScrollbar(boolean visible){
        if(!visible){
            scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
            scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_NEVER);
        }else{
            scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
            scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        }

    }

    public static void main(String[] args) {
        JFrame main = new Main();
        main.setSize(600,400);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        main.setVisible(true);
    }
}