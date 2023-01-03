import java.util.Random;


public class Quest3T {
    public static void main(String[] args) {
        Object obj = new Object();
        Thread a = new Thread(new CntInter("A城", obj));
        Thread b = new Thread(new CntInter("B城", obj));
        a.start();
        b.start();
    }
}

class CntInter implements Runnable{
    private String dest;
    private Object lock;

    CntInter(String dest, Object lock) {
        this.dest = dest;
        this.lock = lock;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++){
            try{Thread.sleep(new Random().nextInt(1000));}
            catch(InterruptedException e){}
        }
        synchronized (lock){
            System.out.println("去" + dest);
            System.exit(0);
        }
    }
}