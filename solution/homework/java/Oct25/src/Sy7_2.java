import java.io.*;
public class Sy7_2 {
    public static void main(String[] args) {
        RandomAccessFile in = null;
        try{
            in = new RandomAccessFile("src/Sy7_2.java","rw");
            long length = in.length();
            long position = 0;
            in.seek(position);
            in.getFilePointer();
            while(position<length){
                String str = in.readLine();
                System.out.println(str);
                position = in.getFilePointer();
            }
        }
        catch(IOException e){}
    }
}
