import java.util.Random;
import java.util.Scanner;

public class Guess {
    public static void main(String[] args) {
        int target = new Random().nextInt(100);
        System.out.println("(Debug): Target is " + target);
        int input = -1;
        Scanner scanner = new Scanner(System.in);
        while((input = scanner.nextInt()) !=  target){
            if(input > target){
                System.out.println("猜大了");
            }else{
                System.out.println("猜小了");
            }
        }
        System.out.println("猜中了");
    }
}
