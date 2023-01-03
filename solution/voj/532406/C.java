import java.util.Scanner;
import java.util.ArrayList;
public class Main{
  public static void main(String args[]){
    Scanner scanner = new Scanner(System.in);
    int t = scanner.nextInt();
    while(t-- != 0){
      int n = scanner.nextInt();
      int k = scanner.nextInt();
      ArrayList<Integer> list = new ArrayList();
      for(int i = 0; i < n; i++){
        list.add(scanner.nextInt());
      }
      int ans = 0;
      for(int i = 0; i < n; i++){
        if(list.get(i) > list.get(k-1)){
          ans++;
        }
      }
      System.out.println(ans);
  
    }
  }
}