import java.util.Scanner;

public class Rev {
    public static String rev(String s){
        StringBuffer buffer = new StringBuffer();
        for (int i = s.length() - 1; i >= 0; i--) {
           buffer.append(s.charAt(i));
        }
        return buffer.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        System.out.println(rev(line));
    }
}
