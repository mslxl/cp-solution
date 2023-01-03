import java.util.Random;

public class Quest3 {
    public static void main(String[] args) {
        Object obj = new Object();
        CntThread a = new CntThread("A城", obj);
        CntThread b = new CntThread("B城", obj);
        a.start();
        b.start();
    }
}

class CntThread extends Thread{
    private String dest;
    private Object lock;

    CntThread(String dest, Object lock) {
        this.dest = dest;
        this.lock = lock;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++){
            try{sleep(new Random().nextInt(1000));}
            catch(InterruptedException e){}
        }
        synchronized (lock){
            System.out.println("去" + dest);
            System.exit(0);
        }
    }
}