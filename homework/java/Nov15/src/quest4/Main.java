package quest4;


import javax.imageio.ImageIO;
import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

class Win extends JFrame{
    private JPanel topPanel = new JPanel();
    private JButton btnOpenImg = new JButton("显示图像");
    private JButton btnDrawImg = new JButton("绘制图像");
    private JButton btnSaveImg = new JButton("保存图像");

    private JLabel image = new JLabel();

    private JPanel bottomPanel = new JPanel();
    private JLabel labelTip = new JLabel("请输入图像名:");
    private JTextField fieldFilePath = new JTextField(20);

    private BufferedImage bufferedImage;

    private static Clip bgm;

    public Win(){
        btnOpenImg.addActionListener(e -> {
            File file = new File(fieldFilePath.getText());
            if(!file.exists()){
                JOptionPane.showMessageDialog(Win.this, "图片不存在 " + fieldFilePath.getText());
                return;
            }
            try {
                bufferedImage = ImageIO.read(new FileInputStream(file));
                image.setIcon(new ImageIcon(bufferedImage));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
        btnDrawImg.addActionListener(e->{
            Graphics graphics = bufferedImage.getGraphics();
            graphics.setColor(Color.ORANGE);
            Font font = new Font("宋体", Font.BOLD, 40);
            graphics.setFont(font);
            graphics.drawString("Hello,World", 100,100);
            bufferedImage.flush();
            image.setIcon(new ImageIcon(bufferedImage));
        });

        btnSaveImg.addActionListener(e->{
            String name = new File(fieldFilePath.getText()).getName() + "_new.png";
            try {
                ImageIO.write(bufferedImage, "png", new File(name));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });


        setLayout(new BorderLayout());

        topPanel.setLayout(new FlowLayout());
        topPanel.add(btnOpenImg);
        topPanel.add(btnDrawImg);
        topPanel.add(btnSaveImg);

        bottomPanel.setLayout(new FlowLayout());
        bottomPanel.add(labelTip);
        bottomPanel.add(fieldFilePath);

        add(topPanel, BorderLayout.NORTH);
        add(image, BorderLayout.CENTER);
        add(bottomPanel, BorderLayout.SOUTH);

        try {
            bgm= AudioSystem.getClip();
            FileInputStream is = new FileInputStream("bgm.wav");
            AudioInputStream ais=AudioSystem.getAudioInputStream(is);
            bgm.open(ais);
        } catch (LineUnavailableException | UnsupportedAudioFileException | IOException e) {
            e.printStackTrace();
        }
        bgm.start();
        bgm.loop(Clip.LOOP_CONTINUOUSLY);
    }
}

public class Main {
    public static void main(String[] args) {
        JFrame frame = new Win();
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
