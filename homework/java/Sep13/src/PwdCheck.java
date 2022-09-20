import java.util.Scanner;

public class PwdCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        boolean ret = line.matches("[a-zA-Z][\\da-zA-Z]{5,11}");
        int numCnt = 0;
        for (int i = 0; i < line.length(); i++) {
            if(Character.isDigit(line.charAt(i))) numCnt++;
        }
        if (ret && numCnt >= 2) System.out.println("密码正确"); else{
            System.out.println("密码错误");
        }
    }
}
