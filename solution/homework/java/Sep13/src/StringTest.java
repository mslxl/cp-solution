public class StringTest {
    public static void main(String[] args) {
        String s = "Hello World!";
        System.out.println("长度值: " + s);
        System.out.println("第二个字符: " + s.charAt(1));
        System.out.println("小 -> 大: " + s.toUpperCase());
        System.out.println("连接: " + s + "How are you?");
    }
}
