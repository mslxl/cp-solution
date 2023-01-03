import java.io.*;
import java.nio.file.Files;

class Student implements Serializable {
    String name;
    int score;

    public Student(String name, int score) {
        this.name = name;
        this.score = score;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", score=" + score +
                '}';
    }
}
public class Quest3 {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Student s1 = new Student("DaMing", 114514);
        Student s2 = new Student("Yukikaze", 1919810);
        Student s3 = new Student("NoName", 11);

        File file = File.createTempFile("obj", "dat");
        ObjectOutputStream oos = new ObjectOutputStream(Files.newOutputStream(file.toPath()));

        oos.writeObject(s1);
        oos.writeObject(s2);
        oos.writeObject(s3);
        oos.flush();
        oos.close();

        ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(file.toPath()));
        System.out.println(ois.readObject());
        System.out.println(ois.readObject());
        System.out.println(ois.readObject());
    }
}
