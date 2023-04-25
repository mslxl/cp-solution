import java.io.File;

public class Quest1 {
    public static void main(String[] args) {
        File dir = new File(".");
        System.out.println(String.format("%s 下所有子目录：", dir.getAbsolutePath()));
        for (File f: dir.listFiles(pathname -> pathname.isDirectory())){
            System.out.println(f.getName());
        }

        System.out.println(String.format("%s 下所有文件名", dir.getAbsolutePath()));
        for (File f: dir.listFiles(pathname -> pathname.isFile())){
            System.out.println(f.getName());
        }
    }
}
