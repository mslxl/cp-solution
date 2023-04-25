import java.util.Scanner;

public class CountChar {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        int cnt[] = new int[3];
        for (int i = 0; i < line.length(); i++) {
            char ch = line.charAt(i);
            if(Character.isDigit(ch)){
                cnt[0]++;
            }else if(Character.isLowerCase(ch)){
                cnt[1]++;
            }else if(Character.isUpperCase(ch)){
                cnt[2]++;
            }
        }

        System.out.println("小写:" + cnt[1]);
        System.out.println("大写:" + cnt[2]);
        System.out.println("数字:" + cnt[0]);
    }
}
