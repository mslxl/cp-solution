import java.io.*;
import java.util.Scanner;

public class Quest3 {
    private static String prompt(String msg, Scanner scanner) {
        System.out.print(msg);
        return scanner.nextLine();
    }
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var fileName = prompt("Filename: ", scanner);
        var output = new File(fileName);
        if(!output.exists()){
            System.out.println("File not exists, program has create it automatically");
        }
        try(var os = new OutputStreamWriter(new FileOutputStream(output))){
            var lines = Integer.parseInt(prompt("Content lines number:", scanner));
            while(lines-- != 0 && scanner.hasNext()){
                os.write(scanner.nextLine());
                os.write('\n');
            }
            os.flush();
        }catch (IOException e){
            throw new RuntimeException(e);
        }
    }
}
