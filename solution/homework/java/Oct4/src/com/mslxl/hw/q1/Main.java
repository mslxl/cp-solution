package com.mslxl.hw.q1;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.util.Arrays;

public class Main extends JFrame {
    JTextField textFieldInput = new JTextField(50);
    JTextField textFieldOutput = new JTextField(50);

    Main(){
        super("计算");
        setLayout(new FlowLayout());

        textFieldOutput.setEditable(false);
        textFieldInput.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updateOutput();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updateOutput();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updateOutput();
            }
        });
        add(textFieldInput);
        add(textFieldOutput);
        setSize(600,400);
    }


    void updateOutput(){
        double result = Arrays.stream(textFieldInput.getText().trim().split(" "))
                .filter((String s)->!s.isEmpty())
                .mapToDouble((String s)-> {
                    try{
                        return Double.parseDouble(s);
                    }catch (NumberFormatException e){
                        return Double.NaN;
                    }
                })
                .average()
                .orElse(0);
        textFieldOutput.setText(result + "");
    }

    public static void main(String[] args) {
        Main app = new Main();
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        app.setVisible(true);
    }

}
