import java.io.File;
import java.io.*;

class ExampleRandomFile {
    public static void main(String[] args) {
        int b;
        byte tom[] = new byte[8];
        try{
            File f = new File("Input.java");
            File f2 = new File("Output.txt");
            FileInputStream in = new FileInputStream(f);
            FileOutputStream out = new FileOutputStream(f2);
            while(( b=in.read(tom,0,8) ) != -1){
                out.write(tom,0,b);
            }
            in.close();
            out.close();
        }
        catch(IOException e){
            System.out.println("File read Error"+e);
        }
    }
}
