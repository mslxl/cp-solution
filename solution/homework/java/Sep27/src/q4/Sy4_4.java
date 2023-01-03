package q4;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class St4_4Listener implements ActionListener{
    private Sy4_4View view;

    St4_4Listener(Sy4_4View view) {
        this.view = view;
    }

    public void actionPerformed(ActionEvent e) {
        JButton bt = (JButton)e.getSource();
        if(bt==view.bt1)
            view.card.first(view.cardPan);
        else if(bt==view.bt2)
            view.card.previous(view.cardPan);
        else if(bt==view.bt3)
            view.card.next(view.cardPan);
        else
            view.card.last(view.cardPan);
    }
}

class Sy4_4View extends JFrame{
    JPanel cardPan, btPan;
    CardLayout card;
    JButton bt1,bt2,bt3,bt4;

    St4_4Listener listener = new St4_4Listener(this);

    public Sy4_4View() {
        JFrame jf = this;
        cardPan = new JPanel();
        btPan = new JPanel();
        card = new CardLayout(5,10);
        bt1 = new JButton("第一页");
        bt2 = new JButton("上一页");
        bt3 = new JButton("下一页");
        bt4 = new JButton("最后页");
        bt1.addActionListener(listener);
        bt2.addActionListener(listener);
        bt3.addActionListener(listener);
        bt4.addActionListener(listener);
        jf.setLayout(null);
        jf.setTitle("卡片式布局");
        jf.setSize(350,300);
        jf.setResizable(false);
        cardPan.setLayout(card);
        cardPan.setBounds(10,10,320,200);
        for(int i=1; i<=4; i++) {
            cardPan.add(new JLabel("第"+i+"页"));
        }
        btPan.setLayout(new GridLayout(1,4));
        btPan.setBounds(10,220,320,25);
        btPan.add(bt1);
        btPan.add(bt2);
        btPan.add(bt3);
        btPan.add(bt4);
        jf.add(cardPan);
        jf.add(btPan);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setVisible(true);
    }

}


public class Sy4_4 {

    public static void main(String[] args) {
        new Sy4_4View();
    }
}
