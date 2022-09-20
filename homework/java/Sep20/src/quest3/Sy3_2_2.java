package quest3;

public class Sy3_2_2 {
    public static void main(String[] args) {
        try {
            User ins = User.class.getDeclaredConstructor().newInstance();
            User.class.getDeclaredMethod("setId", int.class).invoke(ins, 1);
            User.class.getDeclaredMethod("setName", String.class).invoke(ins, "Java1");
            System.out.println(User.class.getDeclaredMethod("sayHello", String.class).invoke(ins, "user1"));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
