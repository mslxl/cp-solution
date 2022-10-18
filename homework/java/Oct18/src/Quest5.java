import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Quest5 {
    private static void cp(String src, String dest){
        try{
            var in = new FileInputStream(src);
            var out = new FileOutputStream(dest);

            var inChannel = in.getChannel();
            var outChannel = out.getChannel();
            inChannel.transferTo(0, inChannel.size(), outChannel);

            in.close();
            out.close();
        }catch (IOException e){
            throw  new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        cp("114514.txt", "after.txt");
    }
}
