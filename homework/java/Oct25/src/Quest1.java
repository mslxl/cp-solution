import java.io.*;

public class Quest1 {
    public static long write(Writer writer){
        final int cnt = 100000;
        long start = System.currentTimeMillis();
        try {
            for (int i = 0; i < cnt; i++) {
                writer.write("" + Math.random());
            }
            writer.flush();
        }catch (Exception e){
            throw  new RuntimeException(e);
        }
        return System.currentTimeMillis() - start;
    }
    public static void main(String[] args) throws IOException {
        File file1 = File.createTempFile("temp", String.valueOf(System.currentTimeMillis()));

        long timeCost1;
        try(FileWriter writer = new FileWriter(file1)){
            timeCost1 = write(writer);
        }catch(Exception e){
            throw e;
        }
        long timeCost2;
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(file1))){
            timeCost2 = write(writer);
        }catch(Exception e){
            throw e;
        }

        System.out.printf("FileWriter costs %d ms\n", timeCost1);
        System.out.printf("BufferWrite costs %d ms\n", timeCost2);
    }
}