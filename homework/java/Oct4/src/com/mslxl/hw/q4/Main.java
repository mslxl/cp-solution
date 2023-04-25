package com.mslxl.hw.q4;

import javax.swing.*;
import java.awt.*;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.util.Arrays;
import java.util.HashMap;

class HeadedLabel extends JPanel {
    HeadedLabel(String head, JComponent component) {
        setLayout(new BorderLayout());
        JLabel label = new JLabel(head);

        add(label, BorderLayout.WEST);
        add(component, BorderLayout.CENTER);
    }
}

class MainWindows extends JFrame{
    MainWindows(){
        super("学生管理系统主窗口");
        setSize(400,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Main extends JFrame {
    private JTextField textFieldUserName = new JTextField(30);
    private JPasswordField textFieldPwd = new JPasswordField(30);

    private JButton btnConfirm = new JButton("确认");
    private JButton btnExit = new JButton("退出");

    private Box linerPanel = Box.createVerticalBox();

    private int cntFail = 0;

    private HashMap<String, String> fakeDb = new HashMap();
    public static char[] md5Char(char[] str) {
        return md5String(new String(str)).toCharArray();
    }
    public static String md5String(String plainText) {
        byte[] secretBytes = null;
        try {
            secretBytes = MessageDigest.getInstance("md5").digest(plainText.getBytes());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        String md5code = new BigInteger(1, secretBytes).toString(16);
        for (int i = 0; i < 32 - md5code.length(); i++) {
            md5code = "0" + md5code;
        }
        return md5code;
    }

    void initFakeDatabase() {
        fakeDb.put("田所浩二", "c4d038b4bed09fdb1471ef51ec3a32cd"); // 密码是 114514
    }

    void makePadding(int top, int left, int bottom, int right) {
        JPanel panel = (JPanel) getContentPane();
        panel.setBorder(BorderFactory.createEmptyBorder(top, left, bottom, right));
    }

    void loginFail(){
        cntFail++;
        if(cntFail > 3){
            JOptionPane.showMessageDialog(this, "输入次数多于 3 次，退出系统", "登录失败", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }else{
            JOptionPane.showMessageDialog(this, "用户名或密码错误", "登录失败", JOptionPane.ERROR_MESSAGE);
        }
    }

    void loginSuccess(){
        setVisible(false);
        new MainWindows().setVisible(true);
    }

    void login() {
        String username = textFieldUserName.getText();
        if (!fakeDb.containsKey(username)){
            loginFail();
            return;
        }
        char[] pwd  = textFieldPwd.getPassword();
        if(!Arrays.equals(md5Char(pwd), fakeDb.get(username).toCharArray())){
            loginFail();
            return;
        }
        Arrays.fill(pwd, '\0');
        loginSuccess();
    }



    Main() {
        super("请输入用户名和密码");
        initFakeDatabase();
        setLayout(new BorderLayout());
        setContentPane(new JPanel());


        btnExit.addActionListener((e) -> System.exit(0));
        btnConfirm.addActionListener((e) -> login());


        linerPanel.add(new HeadedLabel("用户名:", textFieldUserName));
        linerPanel.add(Box.createVerticalStrut(16));
        linerPanel.add(new HeadedLabel("密码   :", textFieldPwd));
        linerPanel.add(Box.createVerticalStrut(16));

        Box buttonBar = Box.createHorizontalBox();
        buttonBar.add(btnConfirm);
        buttonBar.add(Box.createHorizontalGlue());
        buttonBar.add(btnExit);
        linerPanel.add(buttonBar);

        add(linerPanel, BorderLayout.CENTER);
        makePadding(20, 40, 20, 40);
        setSize(600, 400);
    }

    public static void main(String[] args) {
        Main app = new Main();
        app.setVisible(true);
    }
}