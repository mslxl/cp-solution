import java.util.Scanner;

public class Stu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int mark[] = new int[n];
        for (int i = 0; i < n; i++) {
            mark[i] = scanner.nextInt();
        }
        int beg, end;
        beg = scanner.nextInt();
        end = scanner.nextInt();

        int max = -1;
        for(int i = beg -1; i < end; i++){
            if(mark[i] > max){
                max = mark[i];
            }
        }
        System.out.printf("%d 到 %d 中，最高成绩为: %d", beg,end, max);

    }
}
