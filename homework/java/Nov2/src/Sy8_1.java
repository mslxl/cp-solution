public class Sy8_1 {
    public static void main(String[] args) {
        Lefthand left;
        Righthand right;
        left = new Lefthand();
        right = new Righthand();
        left.start();
        right.start();
    }
}
class Lefthand extends Thread {
    public void run() {
        for(int i=1;i<=5;i++){
            System.out.println("A");
            try{sleep(500);}
            catch(InterruptedException e){}
        }
    }
}
class Righthand extends Thread {
    public void run() {
        for(int i=1;i<=5;i++){
            System.out.println("B");
            try{sleep(300);}
            catch(InterruptedException e){}
        }
    }
}
